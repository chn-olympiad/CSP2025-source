#include <bits/stdc++.h>
using namespace std;
int number[11] = {0};
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string n;
	cin>>n;
	for (int i = 0; i < n.size(); i++) {
		switch (n[i]) {
			case 48:
				number[0]++;
				break;
			case 49:
				number[1]++;
				break;
			case 50:
				number[2]++;
				break;
			case 51:
				number[3]++;
				break;
			case 52:
				number[4]++;
				break;
			case 53:
				number[5]++;
				break;
			case 54:
				number[6]++;
				break;
			case 55:
				number[7]++;
				break;
			case 56:
				number[8]++;
				break;
			case 57:
				number[9]++;
				break;
			default:
				number[10]++;
		}
	}
	for (int i = 0; i < number[9]; i++) {
		cout<<9;
	}
	for (int i = 0; i < number[8]; i++) {
		cout<<8;
	}
	for (int i = 0; i < number[7]; i++) {
		cout<<7;
	}
	for (int i = 0; i < number[6]; i++) {
		cout<<6;
	}
	for (int i = 0; i < number[5]; i++) {
		cout<<5;
	}
	for (int i = 0; i < number[4]; i++) {
		cout<<4;
	}
	for (int i = 0; i < number[3]; i++) {
		cout<<3;
	}
	for (int i = 0; i < number[2]; i++) {
		cout<<2;
	}
	for (int i = 0; i < number[1]; i++) {
		cout<<1;
	}
	for (int i = 0; i < number[0]; i++) {
		cout<<0;
	}
	return 0;
}
