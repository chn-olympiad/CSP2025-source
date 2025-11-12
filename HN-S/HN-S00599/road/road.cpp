#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 5, M = 2e6 + 5;

int n, m, k, c[N], a[15][N], fa[N], cnt, ans = 1e18;

bool vis[N];

struct E {
	int x, y, w;
} e[M], tmp[M];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int xx = find(x), yy = find(y);
	if (xx != yy) fa[xx] = yy;
}

bool cmp(E x, E y) {
	return x.w < y.w;
}

int get() {
	int res = 0;
	cnt = m;
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		e[i] = tmp[i];
	for (int i = 1; i <= k; i++) if (vis[i]) {
		res += c[i];
		for (int j = 1; j <= n; j++)
			e[++ cnt] = {n + i, j, a[i][j]};
	}
	sort(e + 1, e + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++) {
		int x = find(e[i].x), y = find(e[i].y);
		if (x == y) continue;
		merge(x, y);
		res += e[i].w;
	}
	return res;
}

void dfs(int cur) {
	if (cur == k + 1) {
		ans = min(ans, get());
		return ;
	}
	vis[cur] = true;
	dfs(cur + 1);
	vis[cur] = false;
	dfs(cur + 1);
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		tmp[i] = {u, v, w};
	}
	if ((k <= 5 && m <= 100000) || (k == 0)) {
		for (int i = 1; i <= k; i++) {
			cin >> c[i];
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		}
		dfs(1);
		cout << ans;
		return 0;
	}
	int las = get();
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
		vis[i] = true;
		ans = min(ans, get());
		if (get() >= las) vis[i] = false;
	}
	cout << get();
	return 0;
}
// unsigned long long CSP_S_2025_RP = -1;
