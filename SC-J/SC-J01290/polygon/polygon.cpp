#include <bits/stdc++.h>
#define int unsigned long long
#define mod 998244353
using namespace std;
int n, a[5010], box[5010], vis[5010], cnt = 0, ans = 0;
void dfs(int x, int step) {
	if (step == x + 1) {
//		for (int i = 1; i <= x; ++i) {
//			cout << box[i] << ' ';
//		}
//		cout << '\n';
		int maxn = 0, sum = 0;
		for (int i = 1; i <= x; ++i) {
			sum += a[box[i]];
			maxn = max(maxn, a[box[i]]);
		}
		if (sum > maxn * 2) {
			++cnt;
			cnt %= mod;
		}
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 0) {
			continue;
		}
		vis[i] = 0;
		box[step] = i;
		dfs(x, step + 1);
		vis[i] = 1;
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; ++i) {
		fill(vis + 1, vis + n + 1, 1);
		dfs(i, 1);
		int m = 1;
		for (int j = 1; j <= i; ++j) {
			m *= j;
		}
		cnt /= m;
		cnt %= mod;
		ans += cnt;
		ans %= mod;
//		cout << ans << '\n';
	}
	cout << ans;
	return 0;
}