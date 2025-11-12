#include <iostream>
#include <cstring>
#include <cstdio>

typedef long long ll;
const int N = 110;
const int mod = 998244353;
int n, m, c[N], cnt[N], s[N];
int f[N][N][N], fac[N], ifac[N], inv[N];
char ch[N];

inline int add (int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	return x;
}

inline int sub (int x, int y) {
	x -= y;
	if (x < 0) x += mod;
	return x;
}

int C (int _n, int _m) {
	if (_n < 0 || _m < 0 || _n < _m) return 0;
	return 1ll * fac[_n] * ifac[_m] % mod * ifac[_n - _m] % mod;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::cin >> n >> m;
	fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
	for (int i = 2; i <= n * 2; i++) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	}
	std::cin >> (ch + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
		cnt[c[i]]++;
	}
	s[0] = cnt[0];
	for (int i = 1; i <= n; i++) 
		s[i] = s[i - 1] + cnt[i];
	f[0][0][0] = 1;
	for (int j = 0; j < n; j++) {
		if (ch[j + 1] == '1') {
			for (int i = 0; i <= std::min(n - m, j); i++)
				for (int k = 0; k <= j; k++)
					f[i][j + 1][k] = f[i][j][k];
			for (int i = 0; i <= j; i++)
				for (int k = 0; k <= j; k++) {
					for (int a = 0; a <= cnt[i + 1]; a++) {
						if (k + a + 1 > j + 1) continue;
						if (s[i] - k < 0) continue;
						f[i + 1][j + 1][k + a + 1] = add(f[i + 1][j + 1][k + a + 1], 
									1ll * f[i][j][k] * (s[i] - k) % mod * C(cnt[i + 1], a) % mod * C(j - k, a) % mod * fac[a] % mod);
					}
				}
		} else {
			for (int i = 0; i <= std::min(n - m, j); i++)
				for (int k = 0; k <= j; k++)
					for (int a = 0; a <= cnt[i + 1]; a++) {
						f[i + 1][j + 1][k + a] = add(f[i + 1][j + 1][k + a], 
										1ll * f[i][j][k] * C(cnt[i + 1], a) % mod * C(j - k, a) % mod * fac[a] % mod);
						f[i + 1][j + 1][k + a + 1] = add(f[i + 1][j + 1][k + a + 1],
										1ll * f[i][j][k] * (s[i] - k) % mod * C(cnt[i + 1], a) % mod * C(j - k, a) % mod * fac[a] % mod);
						if (a) f[i + 1][j + 1][k + a] = add(f[i + 1][j + 1][k + a],
										1ll * f[i][j][k] * C(cnt[i + 1], a) % mod * C(j - k, a - 1) % mod * fac[a] % mod);
					}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - m; i++)
		ans = add(ans, 1ll * f[i][n][s[i]] * fac[n - s[i]] % mod);
	std::cout << ans;
	return 0;	
}
