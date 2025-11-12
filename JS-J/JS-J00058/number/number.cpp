#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (char c : s) {
		if (isdigit(c)) {
			cnt[c - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			printf("%d", i);
		}
	}
	return 0;
}
