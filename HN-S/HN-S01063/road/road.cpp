#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 100, M = 1e4 + 100;
int n, m, k1, a[11][M], c[N], fa[N], res = 0;
struct node{
	int u, v, w, opt;
} g[M];
struct edge{
	int v, w, opt;
};
vector <edge> e[N], e2[N];
bool cmp(node i, node j){
	return i.w < j.w;
}
inline int find(int i){
	if (fa[i] == i) return fa[i];
	fa[i] = find(fa[i]);
}
inline void join(int i, int j){
	if (find(fa[i]) != find(fa[j])){
		fa[i] = find(fa[j]);
	}
}
inline int kru(){
	sort(g + 1, g + 1 + m, cmp);
	int cnt = 0, ans = 0;
	for (int i = 1; i <= m; i ++){
		if (cnt == n - 1) break;
		if (find(g[i].u) != find(g[i].v)){
			cnt ++, ans += g[i].w;
			join(g[i].u, g[i].v);
			edge l1, l2;
			l1.v = g[i].v, l1.w = g[i].w, l1.opt = 1;
			l2.v = g[i].u, l2.w = g[i].w, l2.opt = 1; 
			e[g[i].u].push_back(l1);
			e[g[i].v].push_back(l2);
			e2[g[i].u].push_back(l1);
			e2[g[i].v].push_back(l2);
//			cout << g[i].u << " " << g[i].v << " " << g[i].w << "\n";
		}
//		cout << cntt << "\n";
	}
	return ans;
}
void dfs(int u, int s, int f, int w1, int num){
	if (w1 > a[s][u]){
		res += a[s][u] - w1, e[f][num].opt = 0;
	}
	for (int i = 0; i < e[u].size(); i ++){
		int v = e[u][i].v, w = e[u][i].w, opt = e[u][i].opt;
		if (opt == 0 || v == f) continue;
		dfs(v, s, u, w, i);
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k1;
	for (int i = 1; i <= m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		g[i].u = u, g[i].v = v, g[i].w = w, g[i].opt = 0;
	}
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1; i <= k1; i ++){
		cin >> c[i];
		for (int j = 1; j <= n; j ++){
			cin >> a[i][j];
		}
	}
	int ans;
	ans = kru();
	for (int i = 0; i <= (1 << k1) - 1; i ++){
		int num = i, k = 1;
		res = 0;
		while (num){
			if (num & 1){
				res += c[k] + a[k][k];
				dfs(k, k, 0, 0, -1);
			}
			k ++, num /= 2;
		}
//		cout << res << " ";
		ans = min(ans, ans + res);
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
