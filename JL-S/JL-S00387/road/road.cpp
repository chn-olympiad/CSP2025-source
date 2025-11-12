#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 10, M = 1e6 + 2e5 + 10, Inf = 0x3f3f3f3f3f3f3f3f;
struct edge {
	int u, v, w;
	bool operator < (const edge &W) const { return w < W.w; }
} ed[M], E[M];
int fa[N], w[20][N], res[20];
int n, m, k, s, flag, ans = Inf;
int findfa(int x) { return fa[x] == x ? x : fa[x] = findfa(fa[x]); }
void kruscal(int v) {
	for(int i = 1; i <= n + k; i ++ ) fa[i] = i;
	for(int i = 1; i <= m; i ++ ) E[i] = ed[i];
	for(int i = 1; i <= n; i ++ ) E[m + i] = {v + n, i, w[v][i]};
	fa[v + n] = s; res[v] += w[v][0]; int cnt = 1;
	sort(E + 1, E + m + n + 1);
	for(int i = 1; i <= m + n; i ++ ) {
		int p = findfa(E[i].u), q = findfa(E[i].v);
		if(p != q) {
			fa[q] = p;
			cnt ++ ; res[v] += E[i].w;
		}
		if(cnt == n + 1) break;
	}
	ans = min(ans, res[v]);
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i ++ ) cin >> u >> v >> w, ed[i] = {u, v, w};
	for(int i = 1; i <= k; i ++ )
		for(int j = 0; j <= n; j ++ ) cin >> w[i][j], flag = w[i][j] != 0 ? 1 : flag;
	if(!flag) {cout << 0; return 0; }
	for(int i = 1; i <= n; i ++ ) fa[i] = i;
	for(int i = 1; i <= m; i ++ ) E[i] = ed[i];
	sort(E + 1, E + m + 1); int cnt = 0;
	for(int i = 1; i <= m; i ++ ) {
		int p = findfa(E[i].u), q = findfa(E[i].v);
		if(p != q) {
			fa[q] = p;
			cnt ++ ; res[0] += E[i].w;
		}
		if(cnt == n - 1) break;
	}
	if(!k) { cout << res[0] << '\n'; return 0; }
	for(int i = 1; i <= k; i ++ ) kruscal(i);
	cout << ans << '\n';
	return 0;
}
