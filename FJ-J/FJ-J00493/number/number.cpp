#include <bits/stdc++.h>
using namespace std;

string s;

void bout (string b) {
	int ans=0;
	for (char i=57; i>48; i--) {
		for (int j=0; j<b.size(); j++) {
			if (b[j] == i) {
				cout << i; 
				ans++;
			}
		}
	}
	for (int i=0; i<b.size(); i++) {
		if (b[i] == 48) cout << 0;
		if (ans == 0) break;
	}
}

void maxn (string a) {
	string b="";
	char c;
	for (int i=0; i<s.size(); i++) {
		c = a[i];
		if (48<=c && c<=57) b += c;
	}
	bout (b);
}

int main() {
	ios::sync_with_stdio(false);
	
	freopen("number4.in", "r", stdin);
	freopen("number4.out", "w", stdout);
	
	cin >> s;
	maxn(s);
	
	return 0;
}
