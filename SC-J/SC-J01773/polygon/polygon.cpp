#include"bits/stdc++.h"
using namespace std;
const int mod = 998244353, N = 5005;
int n, a[N];
int maxa;
long long ans;
long long C(int n, int m) {
	long long re = 1;
	for (int i = n, j = 1; j <= m; i--, j++)
		re = (re * i / j) % mod;
	return re;
}
void dfs(int i, int cnt, int sum, int mx) {
	if (i > n) {
		if (cnt >= 3 && sum > mx * 2)
			ans++;
		return;
	}
	dfs(i + 1, cnt + 1, sum + a[i], max(mx, a[i]));
	dfs(i + 1, cnt, sum, mx);
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], maxa = max(maxa, a[i]);
	if (maxa == 1) {
		long long ans = 0;
		for (int m = 3; m <= n; m++)
			ans = (ans + C(n, m)) % mod;
		cout << ans;
		return 0;
	}
	dfs(1, 0, 0, 0);
	cout << ans % mod;
	return 0;
}