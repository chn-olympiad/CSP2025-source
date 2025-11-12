#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int maxn = 5000;
constexpr int mod = 998244353;
int n, a[maxn + 10];
LL dp[maxn + 10][maxn + 10];
LL pw[maxn + 10];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	pw[0] = 1;
	for (int i = 1; i <= 5000; ++i) pw[i] = pw[i-1] * 2 % mod;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 5000; ++j) {
			int lst = j - a[i];
			if (lst >= 0) dp[i][j] = (dp[i-1][j] + dp[i-1][lst]) % mod;
			else dp[i][j] = (dp[i-1][j] + pw[i-1]) % mod;
		}
	}
	LL ans = 0;
	for (int i = 3; i <= n; ++i) ans = (ans + dp[i-1][a[i]]) % mod;
	cout << ans << "\n";
	return 0;
}

