#include<bits/stdc++.h>
using namespace std;
string s;
int ton[110];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.length();
	if(len == 1) cout << s;
	else {
		for(int i=0;i<len;i++) {
			if(s[i] >= '0' && s[i] <= '9') {
				ton[(s[i] - '1') + 1]++;
			}
		}
		for(int i=9;i>=0;i--) {
			if(ton[i] == 0) continue;
			for(int j=1;j<=ton[i];j++) cout << i; 
		}
	}
	cout << '\n';
	return 0;
}
