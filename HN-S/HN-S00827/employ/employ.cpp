#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 505, ko = 998244353;

int n, m, c[kMaxN], f[20][1 << 19];
string s;

int P(int x) {
	int s = 0;
	for (; x; x -= x & -x) {
		s++;
	}
	return s;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	int v = 1, b = 0;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		b |= !c[i] || s[i] == '0';
		v = 1LL * v * (i + 1) % ko;
	}
	if (n == m) {
		cout << (!b ? v : 0);
	} else {
		f[0][0] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 1 << n; j++) {
				for (int k = 0; k < n; k++) {
					if (!(j >> k & 1)) {
						if (i >= c[k] || s[P(j)] == '0') {
							f[i + 1][j | 1 << k] = (f[i + 1][j | 1 << k] + f[i][j]) % ko;
						} else {
							f[i][j | 1 << k] = (f[i][j | 1 << k] + f[i][j]) % ko;
						}
					}
				}
			}
		}
		int a = 0;
		for (int i = 0; i <= n - m; i++) {
			a = (a + f[i][(1 << n) - 1]) % ko;
		}
		cout << a;
	}
	return 0;
}
