#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string t[12];
	int k = s.size();
	for (int i = 0; i < k; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[s[i] - '0'] += s[i];
		}
	}
	for (int i = 9; i >= 0; i--) {
		cout << t[i];
	}
	return 0;
}
