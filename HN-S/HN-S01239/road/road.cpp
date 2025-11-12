#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int K = 15;
const int M = 1e6 + 5;
int n, m, k;
int fa[N + K];
int c[K][N];
int find(int x) {
	return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}
bool vis[N];
void init() {
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	memset(vis, 0, sizeof vis);
	return ;
}
struct edge {
	int u, v, w, id;
}e[(M - 5) + (K - 5) * (N - 5) + 5];
int cnt;
bool cmp1(edge x, edge y) {
	return x.w < y.w;
}
bool cmp2(edge x, edge y) {
	return x.id < y.id;
}
int ans;
int kruskal() {
	init();
	int res = 0;
	sort(e + 1, e + 1 + cnt, cmp1);
	int tot = 0;
	for (int i = 1; i <= cnt; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		// cout << i << " " << u << " " << v << " " << e[i].w << "\n";
		if (u != v) {
			fa[u] = v;
			res += e[i].w;
			if (u <= n && !vis[u]) {
				vis[u] = 1;
				tot++;
			}
			if (v <= n && !vis[v]) {
				vis[v] = 1;
				tot++;
			}
			if (tot == n) {
				sort(e + 1, e + 1 + cnt, cmp2);
				return res;
			}
		}
	}
	return res;
}
int ct[K], ct1;
void dfs(int cur) {
	int res = 0;
	for (int i = 1; i <= ct1; i++) {
	// 	cout << ct[i] << " ";
		res += c[ct[i]][1];
		for (int j = 2; j <= n + 1; j++) {
			cnt++;
			e[cnt] = {n + ct[i], j - 1, c[ct[i]][j], cnt};
		}
	}
	ans = min(ans, kruskal() + res);
	// cout << res << " " << kruskal() << " " << ans << "\n";
	cnt = m;
	// cout << cnt << "\n";
	for (int i = cur + 1; i <= k; i++) {
		ct[++ct1] = i;
		dfs(i);
		ct1--;
	}
	return ;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	init();
	int u, v, w;
	cnt = m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		e[i] = {u, v, w, i};
	}
	ans = kruskal();
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		ct[++ct1] = i;
		dfs(i);
		ct1--;
	}
	cout << ans;
	return 0;
}
/*
rp++
*/

