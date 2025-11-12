#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
bool vis[N];
pair<int, int> op[N];
int n, m, k, ct, sum, ans = 1e18, fa[N], ww[N], a[15][10005];
struct Edge {
	int u, v, w;
	bool operator<(const Edge& cp) const {
		return w < cp.w;
	}
} e[N], cs[N], ne[N];
int find(int x) {
	return x == fa[x] ? x : fa[x]=find(fa[x]);
}
void dfs(int pos, int o = 0) {
	if(pos > k) {
		for(int i = 1; i <= ct; i++) ne[i] = cs[i];
		sort(ne+1, ne+ct+1);
		int cct = 0, ns = sum;
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		for(int i = 1; i <= ct; i++) {
			int u = ne[i].u, v = ne[i].v, w = ne[i].w;
			int fu = find(u), fv = find(v);
			if(fu != fv) {
				cct++;
				fa[fu] = fv;
				ns += w;
			}
			if(cct == n+o-1) break;
		}
		ans = min(ans, ns);
		return;
	}
	dfs(pos+1, o);
	vis[pos] = 1, sum += ww[pos];
	for(int i = 1; i <= n; i++)
		cs[++ct] = {n+pos, i, a[pos][i]};
	dfs(pos+1, o+1);
	vis[pos] = 0, sum -= ww[pos];
	ct -= n;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0), cout.tie(0); 
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	} sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if(fu != fv) {
			ct++;
			fa[fu] = fv;
			cs[ct] = {e[i].u, e[i].v, e[i].w};
		}
		if(ct == n-1) break;
	}
	for(int i = 1; i <= k; i++) {
		cin >> ww[i];
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
