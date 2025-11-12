#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, c[20], a[20][100010], dis[100010][20], fa[100010], ans;
bool vis[1010][1010];
struct edge {
	int x, y, w;
	friend bool operator < (edge a, edge b) {
		return a.w < b.w;
	}
}e[5000010];
multiset <edge> q;
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &e[i].x, &e[i].y, &e[i].w);
		q.insert(e[i]);
	}
	while (q.size() > n * n + m) q.erase(--q.end());
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int minn = 1e18;
			for (int p = 1; p <= k; p++) {
				minn = min(minn, a[p][i] + a[p][j] + c[p]);
			}
			q.insert({i, j, minn});
			if (q.size() > n * n + m) q.erase(--q.end());
		}
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + 1 + m);
	while (q.size()) {
		edge op = *q.begin();
		q.erase(q.begin());
		if (find(op.x) == find(op.y)) continue;
		ans += op.w;
		fa[find(op.y)] = op.x;
	}
	cout << ans;
	return 0;
}
