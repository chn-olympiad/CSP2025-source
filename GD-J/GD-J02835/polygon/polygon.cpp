#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3 + 10, mod = 998244353;
inline int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)
			(ans *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ans;
}
int a[N], dp[N];
int n;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		(ans += accumulate(dp, dp + a[i] + 1, 0ll)) %= mod;
		for (int j = N - a[i] - 5; ~j; j--)
			dp[j + a[i]] += dp[j];
		// for (int i = 0; i <= 15; i++)
		// 	cout << dp[i] << ' ';
		// cout << ans << '\n';
	}
	cout << (qpow(2, n) - 1 + mod - ans) % mod;
}
