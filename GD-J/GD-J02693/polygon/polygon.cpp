#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
//4  polygon
int n, a[5500], vis[5500], maxx, sum, cnt;
void dfs(int deep) {
	if (deep == n + 1) {
		if (sum > maxx * 2) cnt++;
		memset(vis, 0, sizeof vis);
		maxx = 0, sum = 0;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			maxx = max(a[i], maxx);
			sum += a[i];
			vis[i] = 1;
			dfs(deep + 1);
			vis[i] = 0;
		}
	}
//	if (sum > maxx * 2) cnt++;
}
int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1);
	cout << cnt;
	return 0;
}
