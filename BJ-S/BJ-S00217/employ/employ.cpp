#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505;
const int mod = 998244353;

int T, n, m, ans, c[N], g[N], h[N], fac[N], ifac[N], f[2][N][N];
string str;

void Add(int &x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

int qpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = 1ll * res * x % mod;
		}
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}

int A(int x, int y) {
	if (x < y) {
		return 0;
	}
	return 1ll * fac[x] * ifac[x - y] % mod;
}

int C(int x, int y) {
	if (x < y) {
		return 0;
	}
	return 1ll * fac[x] * ifac[x - y] % mod * ifac[y] % mod;
}

void work(int cid) {
	cin >> n >> m >> str;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
	}
	ifac[n] = qpow(fac[n], mod - 2);
	for (int i = n; i >= 1; i--) {
		ifac[i - 1] = 1ll * ifac[i] * i % mod;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		h[c[i]]++;
	}
	g[0] = h[0];
	for (int i = 1; i <= n; i++) {
		g[i] = g[i - 1] + h[i];
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i - 1, n - m); j++) {
			int c = min(i - 1, g[j]);
			if (str[i - 1] == '1') {
				for (int k = 0; k <= c; k++) {
					Add(f[1][j][k], f[0][j][k]);
				}
			}
			if (j + 1 <= n - m) {
				if (str[i - 1] == '0') {
					for (int k = c; k >= 0; k--) {
						Add(f[0][j][k + 1], 1ll * f[0][j][k] * (g[j] - k) % mod);
					}
					c++;
					for (int k = 0; k <= c; k++) {
						if (!f[0][j][k]) {
							continue;
						}
						for (int dk = 0; dk <= h[j + 1] && dk + k <= i; dk++) {
							Add(f[1][j + 1][k + dk], 1ll * f[0][j][k] * C(i - k, dk) % mod * A(h[j + 1], dk) % mod);
						}
					}
				} else {
					for (int k = c; k >= 0; k--) {
						f[0][j][k + 1] = 1ll * f[0][j][k] * (g[j] - k) % mod;
					}
					f[0][j][0] = 0;
					c++;
					for (int k = 0; k <= c; k++) {
						if (!f[0][j][k]) {
							continue;
						}
						for (int dk = 0; dk <= h[j + 1] && dk + k <= i; dk++) {
							Add(f[1][j + 1][k + dk], 1ll * f[0][j][k] * C(i - k, dk) % mod * A(h[j + 1], dk) % mod);
						}
					}
				}
			}
		}
		for (int j = 0; j <= min(i, n - m); j++) {
			for (int k = 0; k <= min(i, g[j]); k++) {
				f[0][j][k] = f[1][j][k];
				f[1][j][k] = 0;
			}
		}
	}
	ans = 0;
	for (int j = 0; j <= n - m; j++) {
		Add(ans, 1ll * f[0][j][g[j]] * fac[n - g[j]] % mod);
	}
	cout << ans << '\n';
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	T = 1;
	for (int cid = 1; cid <= T; cid++) {
		work(cid);
	}

	return 0;
}