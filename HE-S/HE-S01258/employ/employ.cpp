#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510, MOD = 998244353;
int n, m, c[MAXN];
string s;
int fac[MAXN], ifac[MAXN];

inline void add(int &a, int b) {
	if (b < 0) b += MOD;
	a += b; if (a >= MOD) a -= MOD;
}
inline int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}
inline int C(int a, int b) {
	return 1ll * fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

namespace work1 {
	const int MAXN = 20;
	int f[2][MAXN][1 << MAXN], lg2[1 << MAXN];
	void solve() {
		for (int i = 2; i < (1 << n); i++) lg2[i] = lg2[i >> 1] + 1;
		f[0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int now = i & 1, lst = now ^ 1;
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k < (1 << n); k++) {
					if (__builtin_popcount(k) != i) continue;
					for (int l = k; l; l ^= (l & -l)) {
						int lb = l & -l, x = lg2[lb] + 1;
						// cout << i << " " << j << " " << k << " " << l << " " << x << endl;
						if (s[i] == '0') add(f[now][j][k], f[lst][j][k ^ lb]);
						else {
							if (i - j < c[x] && j > 0) add(f[now][j][k], f[lst][j - 1][k ^ lb]);
							if (i - 1 - j >= c[x]) add(f[now][j][k], f[lst][j][k ^ lb]);
						}
					}
					// cout << i << " " << j << " " << k << ": " << f[now][j][k] << endl;
				}
			}
		}
		int ans = 0;
		for (int i = m; i <= n; i++) {
			add(ans, f[n & 1][i][(1 << n) - 1]);
		}
		cout << ans << endl;
	}
}

namespace work2 {
	int cnt[MAXN];
	void solve() {
		for (int i = 1; i <= n; i++) {
			cnt[c[i]]++;
		}
		int sum = 0, ans = 1;
		for (int i = n; i >= 1; i--) {
			if (!cnt[i]) continue;
			if (sum + cnt[i] > n - i + 1) {
				cout << fac[n] << endl;
				return;
			}
			ans = 1ll * ans * C(n - i + 1 - sum, cnt[i]) % MOD;
			sum += cnt[i];
		}
		cout << (fac[n] - ans + MOD) % MOD << endl;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> s; s = " " + s;
	for (int i = 1; i <= n; i++) cin >> c[i];

	fac[0] = 1; for (int i = 1; i < MAXN; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);
	for (int i = MAXN - 1; i >= 1; i--) ifac[i - 1] = 1ll * ifac[i] * i % MOD;

	if (n <= 18) {
		work1::solve();
	}
	else {
		work2::solve();
	}

	return 0;
}