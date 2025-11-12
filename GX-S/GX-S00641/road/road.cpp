#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 66;
struct node{
	int to,w;
};
bool vis[N];
int dis[N],f[N];
int n,m,k,ans;
vector <node> e[N];
void bfs(){
	priority_queue <pair<int,int>> q;
	for (int i = 1; i <= n + k; ++i){
		dis[i] = 2e18;
		vis[i] = 0;
	}
	dis[1] = 0;
	q.push({0,1});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < (int)e[u].size(); ++i){
			int v = e[u][i].to,z = e[u][i].w;
			if (vis[v]) continue;
			if (dis[v] > z){
				dis[v] = dis[u] + z + f[v];
				q.push(make_pair(dis[v] * -1,v));
			}
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for (int i = 1; i <= k; ++i){
		cin >> f[i + n];
		for (int j = 1; j <= n; ++j){
			int z;
			cin >> z;
			e[i + n].push_back({j,z});
			e[j].push_back({i + n,z});
		}
	}
	bfs();
	for (int i = 1; i <= n; ++i){
		ans = max(ans,dis[i]);
	}
	cout << ans;
	return 0;
}
