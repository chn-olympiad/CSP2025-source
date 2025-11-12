#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int INF = 0x3f3f3f3f;
int n,m,k,ans;
int dist[N];
int vis[N];
int c[15];
vector<int> a[15];
vector<pair<int,int>> g[N];
void dij(int s){
	for (int i = 1;i <=n+k;i++){
		dist[i] = INF;
		vis[i] = 0;
	} 
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,s});
	dist[s] = 0;
	
	while (pq.size()){
		int u = pq.top().second;
		
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (auto [v,w]: g[u]){
			if (dist[v] > dist[u] + w){
				dist[v] = dist[u]+w;
				ans+=w;
				
				cout << ans << endl;
				pq.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m>>k;
	for (int i = 0;i < m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	int node = n;
	for (int i = 1;i <= k;i++){
		int u;
		cin >> u;
		c[i] = u;
		node++;
		for (int j = 1;j <= n;j++){
			int x;
			cin >> x;
			a[j].push_back(x);
			g[node].push_back({j,x});
			g[j].push_back({node,x});
		}
	}
	dij(1);
	for (int i = 1;i <= n;i++){
		cout << dist[i ] << " ";
	}
	cout << endl;
	cout << ans << endl;
	return 0;
}
