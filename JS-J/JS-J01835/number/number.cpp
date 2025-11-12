#include<bits/stdc++.h>
using namespace std;

string s = "";

bool a(char x, char y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	sort(s.begin(), s.begin() + s.size(), a);
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cout << s[i];
		}
	}
	return 0;
}
