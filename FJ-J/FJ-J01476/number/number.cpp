#include <bits/stdc++.h>
using namespace std;
int num[10];
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (char i : s) {
		if ('0' <= i && i <= '9') {
			num[i - 48]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < num[i]; j++) {
			cout << i;
		}
	}
}

