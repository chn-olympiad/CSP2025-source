#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b[100];
	int a,c = 0;
	cin >> s;
	a = s.size;
	if(a == 1){
		cout << s;
		return 0;
	}
	for(int i = 0; i < a;i++){
		b[i] = s;
	}
	for(int i = 0; i < a;i++){
		if(b[i] == "1") c = 1;
		if(b[i] == "2") c = 2;
		if(b[i] == "3") c = 3;
		if(b[i] == "4") c = 4;
		if(b[i] == "5") c = 5;
		if(b[i] == "6") c = 6;
		if(b[i] == "7") c = 7;
		if(b[i] == "8") c = 8;
		if(b[i] == "9") c = 9;
		if(b[i] == "0") c = 0; 
	}
	cout << c;
	return 0;
}

