#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e2 + 10;
const int mod = 998244353;

/*
大致是钦定一下哪些位置走人了，
那么会得到一些限制，形如第 i 位要 <=x_i 或者 >x_i。
这东西很经典，可以容斥做。
于是找到一种方法把容斥系数带进 dp 里跑就行了。
这个我还不会。 
没时间了，搞搞暴力走人了。
*/

inline void cadd(int &x, int y) { x += y, x < mod || (x -= mod); }

int n, m, a[MAXN]; char p[MAXN];

namespace bruteforce {
	
	int dp[19][1 << 18];
	
	void solve() {
		for (int i = 0; i < n; i++) a[i] = a[i + 1];
		**dp = 1;
		for (int s = 0; s < 1 << 18; s++) {
			for (int i = 0; i < n; i++) {
				if (!dp[i][s]) continue;
				for (int j = 0; j < n; j++) {
					if (s >> j & 1) continue;
					if (i >= a[j] || p[__builtin_popcount(s) + 1] == '0') {
						cadd(dp[i + 1][s | 1 << j], dp[i][s]);
					} else cadd(dp[i][s | 1 << j], dp[i][s]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= n - m; i++) cadd(ans, dp[i][(1 << n) - 1]);
		printf("%d", ans);
	}
	
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, p + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n <= 18) bruteforce::solve();
	else if (m == n) {
		int ans = 1;
		for (int i = 1; i <= n; i++) ans = (ll)ans * i % mod;
		for (int i = 1; i <= n; i++) if (p[i] == '0') ans = 0;
		for (int i = 1; i <= n; i++) if (a[i] == 0) ans = 0;
		printf("%d", ans);
	}
}
