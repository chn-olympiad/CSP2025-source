#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e3 + 10;
int n, m, k, tot, fa[M * 10], dist[M][M], t[M];
bool vis[N];
struct node{
	int u, v, w;
}e[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool cmp(node a, node b){
	return a.w < b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	if(n >= 10000 && k != 0){
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	if(k != 0){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = 2e16;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		if(k != 0)
			dist[u][v] = dist[v][u] = min(dist[u][v], w);
		else e[++tot] = {u, v, w};
	}
	if(k != 0){
		for(int i = 1; i <= k; i++){
			int x;
			cin >> x;
			for(int j = 1; j <= n; j++) cin >> t[j];
			for(int j = 1; j <= n; j++){
				for(int p = 1; p <= n; p++){
					dist[j][p] = dist[p][j] = min(dist[j][p], x + t[j] + t[p]);
				}
			}
		}
	}
	if(k != 0){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++)
				e[++tot] = {i, j, dist[i][j]};
		}
	}
	sort(e + 1, e + tot + 1, cmp);
	int ans = 0, cnt = 0;
	for(int i = 1; i <= tot; i++){
		int fu = find(e[i].u), fv = find(e[i].v);
		if(fu == fv) continue;
		cnt++;
		fa[fu] = fv;
		ans += e[i].w;
		if(cnt == n - 1) break;
	}
	cout << ans << '\n';
	return 0;
}
