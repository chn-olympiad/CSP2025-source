#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n, m, k, ans, c[15], p[15], t[10005], fa[10005], a[15][10005];
struct node{
	int u, v, w;
}e[1100005], g[1100005];
int find(int x){
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
void merge(int x, int y){
	fa[x] = y;
}
bool cmp(node x, node y){
	return x.w < y.w;
}
int kruskal(int edg){
	for(int i = 1; i <= edg; i++){
		g[i] = e[i];
	}
	for(int i = 0; i <= n; i++){
		fa[i] = i;
	}
	sort(g + 1, g + edg + 1, cmp);
	int sum = 0;
	for(int i = 1; i <= edg; i++){
		int x = g[i].u, y = g[i].v, z = g[i].w;
		if(find(x) != find(y)){
			sum += z;
			merge(find(x), find(y));
		}
	}
	return sum;
}
void dfs(int step){
	if(step > k){
		int sum = 0, pos = m;
		for(int i = 1; i <= n; i++){
			t[i] = 1e18;
		}
		for(int i = 1; i <= k; i++){
			if(p[i] == 1){
				sum += c[i];
				for(int j = 1; j <= n; j++){
					t[j] = min(t[j], a[i][j]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(t[i] > 1e10){
				continue;
			}
			e[++pos] = {0, i, t[i]};
		}
		ans = min(ans, sum + kruskal(pos));
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
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	ans = 1e18; 
	dfs(1);
	cout << ans << " ";
	return 0;
}
//n^2^k+m;
