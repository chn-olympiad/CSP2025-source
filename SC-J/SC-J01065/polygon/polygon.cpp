#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n;
int a[N];
int ans = 0;
void dfs(int u, int tot, int ce, int mx, const int n) {
	if (u > n) {
		if (ce < 3) {
			return ;
		}
		if (tot > 2 * mx) {
			ans++;
		}
		return ;
	}
	dfs(u + 1, tot + a[u], ce + 1, max(mx, a[u]), n);
	dfs(u + 1, tot, ce, mx, n);
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0, 0, n);
	cout << ans << '\n';
	return 0;
}
