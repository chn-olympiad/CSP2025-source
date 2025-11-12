#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string as[10];

bool num(char c){
	if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
		return true;
	}
	return false;
}

int nm(char c){
	if(c == '0'){
		return 0;
	}
	if(c == '1'){
		return 1;
	}
	if(c == '2'){
		return 2;
	}
	if(c == '3'){
		return 3;
	}
	if(c == '4'){
		return 4;
	}
	if(c == '5'){
		return 5;
	}
	if(c == '6'){
		return 6;
	}
	if(c == '7'){
		return 7;
	}
	if(c == '8'){
		return 8;
	}
	return 9;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string n;
	cin >> n;
	for(int i=0; i<n.size(); i++){
		if(num(n[i])){
			as[nm(n[i])] += n[i];
		}
	}
	for(int i=9; i>=0; i--){
		cout << as[i];
	}
	return 0;
}
