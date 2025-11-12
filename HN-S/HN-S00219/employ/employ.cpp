#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 505, mod = 998244353;

LL n, m, c[N], f[1 << 19][20];
string s;

int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	f[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) sum += (i >> j) & 1;
		if (sum == n) continue;
		for (int j = 0; j <= sum; j++) {
			if (!f[i][j]) continue;
			for (int k = 1; k <= n; k++) {
				if (i & (1 << k - 1)) continue;
				if (s[sum + 1] == '0' || c[k] <= j) {
					f[i + (1 << k - 1)][j + 1] += f[i][j];
					f[i + (1 << k - 1)][j + 1] %= mod;
				} else {
					f[i + (1 << k - 1)][j] += f[i][j];
					f[i + (1 << k - 1)][j] %= mod;
				}
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i <= n - m; i++) {
		ans += f[(1 << n) - 1][i];
	}
	cout << ans;
	return 0;
}
