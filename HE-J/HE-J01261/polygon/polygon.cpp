#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MAXN = 5e3 + 5;
LL a[MAXN], n, lst[MAXN], c[MAXN], maxnum[MAXN], ans, vis[MAXN];

void dfs(LL p, LL maxx, LL cur) {
	if (cur >= 3) {
		c[0] = maxnum[0] = 0;
		for (LL i = 1; i <= cur; i++) {
			c[i] = c[i-1] + lst[i];
			maxnum[i] = max(lst[i], maxnum[i-1]);
		}
		if (c[cur] > 2 * maxnum[cur]) {
			ans++;
		}
	}
	
	for (LL i = maxx + 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			lst[p + 1] = a[i];
			dfs(p + 1, max(maxx, i), cur + 1);
			vis[i] = false;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	dfs(0, 0, 0);
	cout << ans << endl;
	return 0;
}
