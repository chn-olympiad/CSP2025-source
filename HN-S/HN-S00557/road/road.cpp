#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u, v, w;
}e[2000005], e2[2000005], e3[2000005];
int n, m, k, now, ans, s, c[15], p[15], a[15][200005], fa[200005];
bool operator < (edge a, edge b){
	return a.w < b.w;
}
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}
void dfs(int step){
	if(step > k){
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		int tmp = now, sum = 0;
		for(int i = 1; i <= now; i++) e3[i] = e2[i];
		for(int i = 1; i <= k; i++){
			if(p[i]){
				sum += c[i];
				for(int j = 1; j <= n; j++) e3[++tmp] = {n + i, j, a[i][j]};
			}
		}
		sort(e3 + 1, e3 + tmp + 1);
		for(int i = 1; i <= tmp; i++){
			if(find(e3[i].u) == find(e3[i].v)) continue;
			merge(e3[i].u, e3[i].v);
			sum += e3[i].w;
			if(sum > ans) return;
		}
		ans = min(ans, sum);
		return;
	}
	p[step] = 1;
	dfs(step + 1);
	p[step] = 0;
	dfs(step + 1);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		if(find(e[i].u) == find(e[i].v)) continue;
		e2[++now] = e[i];
		merge(e[i].u, e[i].v);
		ans += e[i].w;
	}
	for(int t = 1; t <= k; t++){
		cin >> c[t];
		for(int i = 1; i <= n; i++) cin >> a[t][i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
