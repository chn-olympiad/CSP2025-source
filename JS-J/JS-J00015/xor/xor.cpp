#include<bits/stdc++.h>

using namespace std;

int dp[1048888];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	memset(dp, -0x3f, sizeof(dp));
	dp[0] = 0;
	int mx = 0, xr = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		xr ^= a;
		mx = max(mx, dp[xr ^ k] + 1);
		dp[xr] = max(dp[xr], mx);
	}
	cout << mx;
	return 0;
}