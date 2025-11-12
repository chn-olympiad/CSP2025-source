#include <bits/stdc++.h>
using namespace std;
string s;
int p[33];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] <= '9' && s[i] >= '0') p[s[i] - '0']++;
	}
	for(int i = 9; i >= 0; i--) {
		for(int j = 1; j <= p[i]; j++) cout << i;
	}
	return 0;
}
