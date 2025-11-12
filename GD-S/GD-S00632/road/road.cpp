#include <bits/stdc++.h>
#define ll long long
#define il inline 
using namespace std;
const int N = 1e4 + 20, M = 1e6 + 20, K = 13;
const ll inf = 1e18;
int n, m, k, c[K], a[K][N], tot, siz, cnt, idx;
ll ans;
struct edge {
	int u, v, w;
	il bool operator < (edge x) const {
		return w < x.w;
	}
} e[M], t[N], tmp[N * K], s[N * K], g[N * K];
int fa[N];
il void init() {
	for (int i = 1; i <= n + k; i++) fa[i] = i;
}
il int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool vis[K];
il ll work() {
	siz = idx = 0;
	for (int i = 1; i <= cnt; i++) if (vis[tmp[i].u - n]) {
		s[++siz] = tmp[i];		
	}
	int sl = 1, tl = 1;
	while (sl <= siz or tl <= tot) {
		if (sl > siz) g[++idx] = t[tl], tl++;
		else if (tl > tot) g[++idx] = s[sl], sl++;
		else {
			if (s[sl].w < t[tl].w) g[++idx] = s[sl], sl++;
			else g[++idx] = t[tl], tl++;
		}
	}
	init();
	ll res = 0; 
	for (int i = 1; i <= idx; i++) {
		int u = g[i].u, v = g[i].v, w = g[i].w;
		int fu = find(u);
		int fv = find(v);
		if (fu == fv) continue;
		fa[fu] = fv;
		res += w;
	}
	return res;
}
il void dfs(int i = 1, ll sum = 0) {
	if (sum >= ans) return ;
	if (i > k) {
		ans = min(ans, sum + work());
		return ;
	}
	dfs(i + 1, sum);
	vis[i] = 1;
	dfs(i + 1, sum + c[i]);
	vis[i] = 0;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			tmp[++cnt] = {n + i, j, a[i][j]};
		}
	}
	sort(tmp + 1, tmp + cnt + 1);
	sort(e + 1, e + m + 1);
	init();
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u);
		int fv = find(v);
		if (fu == fv) continue;
		ans += w;
		fa[fu] = fv;
		t[++tot] = e[i];
	}
	dfs();
	cout << ans;
}
