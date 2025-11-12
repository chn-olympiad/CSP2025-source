#include<bits/stdc++.h>
#define N 10017
#define K 12
#define INF 10000000000
#define ll long long
using namespace std;
struct Edge{
	int v;
	ll w;
};
vector<Edge> g[N];
int n, m, k, tot;
int c[N];
int a[K][N];
bool cg[N], vis[N];
ll prim(){
	priority_queue<pair<int, int> > q;
	q.push({0, 1});
	for(int i = 1;i <= tot;i++){
		vis[i] = 0;
	}
	ll ans = 0;
	while(!q.empty()){
		int u = q.top().second;
		int w = q.top().first * -1;
		q.pop();
		if(vis[u])continue;
		ans += w;
		vis[u] = 1;
		for(int i = 0;i < g[u].size();i++){
			Edge e = g[u][i];
			if(!vis[e.v]){
				q.push({-e.w, e.v});
			}
		}
	}
	return ans;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	ll ans = INF;
	for(int i = 0;i < (1 << k);i++){
		ll v = 0;
		tot = n;
		for(int j = 1;j <= k;j++){
			if(i & (1 << j - 1)){
				v += c[j];
				tot++;
				for(int x = 1;x <= n;x++){
					g[tot].push_back({x, a[j][x]});
					g[x].push_back({tot, a[j][x]});
				}
			}
		}
		v += prim();
		ans = min(ans, v);
	}
	cout << ans << '\n';
	
	return 0;
}
