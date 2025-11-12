#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int dp[5005];
int a[5005];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i] + 1; j <= 5001; j++) (ans += dp[j]) %= mod;
		for (int j = 5001; ~j; j--) (dp[min(j + a[i], 5001)] += dp[j]) %= mod;
	}
	cout << ans;
	return 0;
}