#include<bits/stdc++.h>
using namespace std;
int main(){
	int s[1500], mumber[1500], big = 0;
	for (int i = 0; i > 1000; i++){
		cin >> s[i];
	}
	for (int i = 0; i < 1500; i++){
		if (s[i] == '0'){
			if (big < 0){
				big = 0;
			}
			mumber + '0';
		}
		if (s[i] == '1'){
			if (big < 1){
				big = 1;
			}
			mumber + '1';
		}
		if (s[i] == '2'){
			if (big < 2){
				big = 2;
			}
			mumber + '2';
		}
		if (s[i] == '3'){
			if (big < 3){
				big = 3;
			}
			mumber + '3';
		}
		if (s[i] == '4'){
			if (big < 4){
				big = 4;
			}
			mumber + '4';
		}
		if (s[i] == '5'){
			if (big < 5){
				big = 5;
			}
			mumber + '5';
		}
		if (s[i] == '6'){
			if (big < 6){
				big = 6;
			}
			mumber + '6';
		}
		if (s[i] == '7'){
			if (big < 7){
				big = 7;
			}
			mumber + '7';
		}
		if (s[i] == '8'){
			if (big < 8){
				big = 8;
			}
			mumber + '8';
		}
		if (s[i] == '9'){
			big = 9;
			mumber + '9';
		}
	}
	for (int i = 0; i < 10; i++)
		cout << mumber[i];
	return 0;
}
