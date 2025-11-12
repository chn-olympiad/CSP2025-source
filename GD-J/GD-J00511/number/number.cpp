#include <bits/stdc++.h>

using namespace std;

string s;
int t[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char & c : s) {
		if (isdigit(c)) {
			++ t[c - 48];
		}
	}
	for (int i = 9; i >= 0; -- i) {
		for (int j = 1; j <= t[i]; ++ j) {
			printf("%d", i);
		}
	}
	return 0;
}
