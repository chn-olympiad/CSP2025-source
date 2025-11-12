#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, s[510], c[510];
ll dp[(1 << 18) + 10][20], mod = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		s[i] = c - '0';
		if (!s[i]) flag = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		int day = __builtin_popcount(i);
		for (int j = 0; j < n; j++) {
			if (!((i >> j) & 1)) continue;
			for (int k = 0; k < day; k++) {
				int pre = (i ^ (1 << j));
				if (k >= c[j] || !s[day - 1]) {
					dp[i][k + 1] += dp[pre][k];
				}
				else dp[i][k] += dp[pre][k];
				dp[i][k] %= mod;
				dp[i][k + 1] %= mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n - m; i++) {
		ans += dp[(1 << n) - 1][i];
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}