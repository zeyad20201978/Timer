#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace sf;
using namespace std;

int main() {
	int seconds;
	cout << "Enter Timer in Seconds: ";
	cin >> seconds;
	RenderWindow window(VideoMode(800,800), "Timer");
	Text text;
	SoundBuffer buf;
	Sound sound;
	Font f;
	if (!f.loadFromFile("pop.ttf")) cout << "There is a problem in the font";
	if (!buf.loadFromFile("timer.mp3")) cout << "There is a problem in the music";
	sound.setBuffer(buf);
	text.setFont(f);
	text.setFillColor(Color(255, 255, 255));
	text.setCharacterSize(50);
	text.setOrigin((float) text.getCharacterSize() /2, (float)text.getCharacterSize() / 2);
	cout << text.getLocalBounds().width;
	text.setPosition(375, 375);
	
x:
	if (seconds == 0) sound.play();
	text.setString(to_string(seconds/3600) + ":" + to_string(seconds % 3600/60) + ":" + to_string(seconds%60));
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color(0,0,0));
		window.draw(text);
		window.display();
		if (seconds)
		{
			this_thread::sleep_for(chrono::seconds(1));
			seconds--;
			goto x;
		}
	}
}