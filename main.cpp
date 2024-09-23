#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void changeColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

char getResponse() {
	char response;
	cout << "(Y/N): ";
	cin >> response;
	response = toupper(response);
	return response;
}

void adjustWindow() {
	HWND consoleWindow = GetConsoleWindow();
	MoveWindow(consoleWindow, 100, 100, 400, 400, TRUE);
}

bool darkSituation(int& points) {
	changeColor(14);
	cout << "49 73 20 69 74 20 77 6F 72 74 68 20 6C 69 76 69 6E 67 3F\n";
	changeColor(7);
	cout << "...\n";
	char decision = getResponse();

	if (decision == 'Y') {
		changeColor(12);
		cout << "68 61 68 61 68 61 68 61\n";
		points -= 2;
		return true;
	}
	else {
		changeColor(12);
		cout << "Error: suicide66666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666\n";
		return false;
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	adjustWindow();
	changeColor(7);

	cout << "Welcome to Adolescent.\n";
	cout << "-----------------------------------------\n";

	char decision;
	int points = 0;
	const int totalSituations = 6;

	string situations[totalSituations] = {
		"You find a lost pet in the street. Do you take it home?",
		"You hear rumors about a classmate being bullied. Will you confront them?",
		"A friend offers you a drink at a party, but you're unsure. Do you accept?",
		"You see a stranger acting suspiciously in your neighborhood. Do you report it?",
		"You have the opportunity to cheat on an exam. Do you go for it?",
		"You discover a hidden talent for art and consider sharing it online. Do you?"
	};

	for (int i = 0; i < 5; ++i) {
		if (rand() % 5 == 0) {
			if (!darkSituation(points)) {
				return 0;
			}
		}
		else {
			int situationIndex = rand() % totalSituations;
			changeColor(14);
			cout << "Situation: " << situations[situationIndex] << "\n";
			changeColor(7);
			cout << "Do you decide to take action?\n";
			decision = getResponse();

			if (decision == 'Y') {
				cout << "You took action and faced the consequences.\n";
				points += 1;
			}
			else {
				cout << "You chose not to act, leaving things as they are.\n";
				points -= 1;
			}
		}

		cout << "-----------------------------------------\n";
	}

	cout << "You have finished the game! Let's see how you did...\n";

	if (points >= 5) {
		changeColor(10);
		cout << "You managed to stay safe. Your choices kept you away from danger.\n";
	}
	else if (points >= 0) {
		changeColor(6);
		cout << "You faced some darkness, but you also made wise choices to protect yourself.\n";
	}
	else {
		changeColor(12);
		cout << "You delved too deep into the shadows, and now the darkness follows you...\n";
	}

	changeColor(7);
	cout << "Thank you for playing 'Adolescent Life: Dark Decisions'.\n";

	return 0;
}
