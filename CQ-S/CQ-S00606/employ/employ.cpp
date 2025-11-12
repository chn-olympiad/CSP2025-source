#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

constexpr int MAXN = 500, mod = 998244353;

int n, m, a[MAXN+5], dp[1 << 18][20], pc[MAXN+5], fac[MAXN+5], inv[MAXN+5];
string s;

inline void inc(int &x, int val) { (x += val) >= mod && (x -= mod); }
inline int qpow(int x, int y = mod - 2) {
	int s = 1;
	while (y) {
		if (y & 1) s = (LL)s * x % mod;
		x = (LL)x * x % mod, y >>= 1;
	}
	return s;
}
inline void init() {
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= MAXN; ++i) {
		fac[i] = (LL)fac[i - 1] * i % mod;
		inv[i] = qpow(fac[i]);
	}
}
inline int P(int x, int y) { return (x < y || x < 0 || y < 0) ? 0 : fac[x] * inv[x - y] % mod; }

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	IOS;
	init();
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) cin >> a[i];
	bool A = true;
	for (int i = 0; i < n; ++i) A &= (s[i] == '1');
	dp[0][0] = 1;
	for (int S = 0; S < (1 << n) - 1; ++S) {
		int cnt = __builtin_popcount(S);
		for (int i = 0; i <= cnt; ++i) {
			if (dp[S][i] == 0) continue;
			for (int j = 0; j < n; ++j) {
				if (S & (1 << j)) continue;
				if (a[j] <= i || s[cnt] == '0') inc(dp[S | (1 << j)][i + 1], dp[S][i]);
				else inc(dp[S | (1 << j)][i], dp[S][i]); 
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - m; ++i) inc(ans, dp[(1 << n) - 1][i]);
	cout << ans;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
