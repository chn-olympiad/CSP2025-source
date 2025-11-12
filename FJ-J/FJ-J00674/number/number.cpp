#include <bits/stdc++.h>
using namespace std;

string s;
vector <char> c;

bool cmp(char x, char y){
	return int(x) > int(y);
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int len = s.length();
	s = " " + s;
	for (int i = 1; i <= len; i++){
		if (s[i] == '9'){
			cout << s[i];
			continue;
		}
		if ('0' <= s[i] && s[i] <= '9'){
			c.push_back(s[i]);
		}
	}
	sort(c.begin(), c.end(), cmp);
	for (int i = 0; i < c.size(); i++){
		cout << c[i];
	}
	
	return 0;
}
