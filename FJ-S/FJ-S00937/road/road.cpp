# include <bits/stdc++.h>
# define N (10002)
using namespace std;

int dis[N], n, m, k, ans;
bool vis[N];

struct node{
	int u;
	int val;
};

vector<node>g[N];
queue<node>q;

int main( ) {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for ( int i = 1; i <= m; ++i ) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		ans += w;
	}
	
	q.push({1,0});
	vis[1] = true;
	
//	while ( !q.empty() ) {
//		node tmp = q.front();
//		q.pop();
//		if ( vis[tmp.u] ) continue;
//		for ( int i = 1; i <= int(g[tmp.u].size()); ++i ) {
//			if ( dis[tmp.u] > dis[g[tmp.u][i].u] + g[tmp.u][i].val ) {
//				dis[tmp.u] = dis[g[tmp.u][i].u] + g[tmp.u][i].val;
//				vis[tmp.u] = true;
//				q.push({tmp.u, dis[tmp.u]});
//			}
//		}
//	}
//	cout << dis[3];
	cout << ans;
	return 0;
	
}
