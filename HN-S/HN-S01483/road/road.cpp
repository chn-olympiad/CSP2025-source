#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 6e6 + 5;
struct node {
	int x, y, w;
	bool operator<(const node &a) const {
		return w < a.w;
	}
} e[M], ee[M];
int n, m, k, fa[N], c[N], a[15][N], ans = 1e9, cnt = 0, kkk = 1e9;
bool vis[N];
int findd(int x) {
	if (fa[x] != x) fa[x] = findd(fa[x]);
	return fa[x];
}
int check() {
	for (int i = 1; i <= n; i++) fa[i] = i;
	cnt = 0;
	for (int i = 1; i <= m; i++) ee[i] = e[i];
	int sum1 = 0;
	for (int i = 1; i <= k; i++) {
		if (vis[i]) {
			for (int j = 1; j <= n; j++) {
				for (int l = j + 1; l <= n; l++) {
					int w = a[i][j] + a[i][l];
					cnt++;
					ee[m + cnt] = {j, l, w};
				}
			}
		}
 	}
 	sort(ee + 1, ee + m + cnt + 1);
	for (int i = 1; i <= cnt + m; i++) {
		int x = findd(ee[i].x), y = findd(ee[i].y);
		if (x != y) {
			sum1 += ee[i].w;
			fa[x] = y;
		}
	}
	if (cnt == 0) kkk = min(kkk, sum1);
	return sum1;
}
void dfs(int u, int sum) {
	if (sum > ans) return;
	if (u > k) {
		ans = min(ans, check() + sum);
		return;
	}
	dfs(u + 1, sum);
	vis[u] = 1;
	dfs(u + 1, sum + c[u]);
	vis[u] = 0;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		e[i] = {x, y, w};
	}
	bool falg = 1;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		falg &= (c[i] == 0);
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j], falg &= (a[i][j] == 0);
		}
	}
	if (k == 0) {
		int ans = 0;
		sort(e + 1, e + m + 1);
		for (int i = 1; i <= m; i++) {
			int x = findd(e[i].x), y = findd(e[i].y);
			if (x != y) {
				ans += e[i].w;
				fa[x] = y;
			}
		}
		cout << ans << '\n';
	} else if (m <= 5 && !falg) {
		dfs(1, 0);
		cout << ans << '\n';
	} else if (falg) {
		cout << 0 << '\n';
	} else {
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}
