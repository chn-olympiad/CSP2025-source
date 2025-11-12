#include <bits/stdc++.h>
using namespace std;
char c[1000005];
bool cmp(char x, char y) {
	return x >= y;
}
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int t = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c[++t] = s[i];
		}
	}
	sort(c + 1, c + 1 + t, cmp);
	for (int i = 1; i <= t; i++) {
		cout << c[i];
	}
	return 0;
}
