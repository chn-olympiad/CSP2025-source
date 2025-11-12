#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, a[5005];
void dfs (int cnt, int sum, int mx) {
	if (sum > 2 * mx)	++ans;
	if (ans >=998244353)	ans -= 998244353;
	if (cnt == n + 1)	return ;
	for (int i = cnt; i <= n; ++i) {
		dfs (i + 1, sum + a[i], a[i]);
	}
	return ;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	sort(a + 1, a + 1 + n);
	dfs (1, 0, 0);
	cout << ans;
	return 0;
}