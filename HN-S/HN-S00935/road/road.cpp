#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 7, M = 2e6, K = 11, INF = 1e18;
int n, m, k, vis[K], cnt, c[K], ans = INF;
int fa[N];
struct edge {
	int u, v, w, id;//id表示边的种类 
}b[M];
bool cmp(edge a, edge b) {return a.w < b.w;}

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){fa[find(x)] = find(y);}

int get() {
	int res = 0, num = 0, vnum = 0;
	for (int i = 1; i <= k; i ++)
		if (vis[i])
			res += c[i];
	for (int i = 1; i <= n + 10; i ++)
		fa[i] = i;
	for (int i = 1; i <= cnt; i ++) {
		int u = b[i].u, v = b[i].v, w = b[i].w, id = b[i].id;
		if (id == 1 && !vis[u - n])
			continue;
		vnum ++;
		if (find(u) == find(v))
			continue;
		merge(u, v);
		num ++;
		res += w;
	}
	int x = find(1);
	for (int i = 1; i <= n; i ++)
		if (find(i) != x)
			return INF;
	return res;
}
void dfs(int u) {
	if (u == k + 1) {
		ans = min(ans, get());
		return;
	}
	dfs(u + 1);
	vis[u] = 1;
	dfs(u + 1);
	vis[u] = 0;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	bool data_A = 0;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i ++) {
		cin >> u >> v >> w;
		b[++ cnt] = {u, v, w, 0};
	}
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		if(c[i] != 0)
			data_A = 1;
		for (int j = 1, w; j <= n; j ++) {
			cin >> w;
			b[++ cnt] = {n + i, j, w, 1};
		}
	}
	sort(b + 1, b + cnt + 1, cmp);
	if (!data_A) {
		for (int i = 1; i <= k; i ++)
			vis[i] = 1;
		cout << get();
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
