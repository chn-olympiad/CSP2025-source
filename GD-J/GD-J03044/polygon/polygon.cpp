#include<bits/stdc++.h>
using namespace std;
const int N = 5007, mod = 998244323;
long long a[N], sum[N], n, ans;
void dfs(long long now, long long len, long long maxn) {
	if (now == n+1) {
		if (maxn*2 < len) ans = (ans + 1) % mod;
		return;
	}
	dfs(now+1, len+a[now], max(a[now], maxn));
	dfs(now+1, len, maxn);
}
long long c[N][N];
void init() {
	c[0][0] = c[1][0] = c[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
		}
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (n < 10) {
		dfs(1, 0, 0);
		cout << ans;
	} else {
		init();
		for (int i = 3; i <= n; ++i) ans = (ans + c[n][i]) % mod;
		cout << ans;
	}
	return 0;
}
