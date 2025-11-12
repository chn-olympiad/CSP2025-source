#include <bits/stdc++.h>
using namespace std;

long long a[20];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	long long size = s.size();
	for (long long i = 0; i < size; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			a[s[i] - '0']++;
		}
	}
	for (long long i = 9; i >= 0; i--) {
		while (a[i]) {
			a[i]--, cout << i;
		}
	}
	return 0;
}
