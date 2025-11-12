#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20;
typedef pair<int, int> pii;
long long n, m, k, ans = 1e18, cnt;
int c[10], a[10][N];
struct Graph{
	vector<pii> G[N];
	void link(int u, int v, int w){
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	long long prim(long long lim, int S){
		priority_queue<pii, vector<pii>, greater<pii>> q;
		array<int, N> dis, vis; dis.fill(1e9), vis.fill(0);
		dis[1] = 0; q.push({0, 1}); long long ans = 0;
		while(!q.empty()){
			auto [d, u] = q.top(); q.pop();
			if(vis[u]) continue;
			ans += d, vis[u] = 1;
			if(ans >= lim) break;
			for(auto [v, w]: G[u]){
				if(v > n && !(S >> (v - n - 1) & 1)) continue;
				if(!vis[v] && w < dis[v]) q.push({dis[v] = w, v});
			}
		}
		return ans;
	}
} G;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		G.link(u, v, w);
	}
	for(int i=0; i<k; i++){
		cin >> c[i];
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
			G.link(n+i+1, j, a[i][j]);
		}
	}
	for(int S=0; S<1<<k; S++){
		long long sum = 0;
		for(int i=0; i<k; i++) if(S >> i & 1) sum += c[i];
		ans = min(ans, G.prim(ans - sum, S) + sum);
	}
	cout << ans;
	return 0;
}
