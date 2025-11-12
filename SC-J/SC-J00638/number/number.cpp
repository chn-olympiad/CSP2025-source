#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int t[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s, w = "";
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			if(s[i] == '0') t[0]++;
			else if(s[i] == '1') t[1]++;
			else if(s[i] == '2') t[2]++;
			else if(s[i] == '3') t[3]++;
			else if(s[i] == '4') t[4]++;
			else if(s[i] == '5') t[5]++;
			else if(s[i] == '6') t[6]++;
			else if(s[i] == '7') t[7]++;
			else if(s[i] == '8') t[8]++;
			else t[9]++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		for(int j = 1; j <= t[i]; j++) cout << i;
	}
	cout << w;
	return 0;
}