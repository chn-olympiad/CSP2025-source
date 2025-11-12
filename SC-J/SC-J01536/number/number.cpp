#include <bits/stdc++.h>

using namespace std;

string s;
int mp[11];

int main() {
#ifdef XYX
	freopen("number4.in", "r", stdin);
	freopen("number4.out", "w", stdout);
#else 
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s;
	for(char c : s) {
		if('0' <= c && c <= '9') {
			++mp[c - '0'];
		}
	}
	
	for(int i = 9;i >= 0;i--) {
		while(mp[i]) {
			--mp[i];
			cout << i;
		}
	}
	
	return 0;
}