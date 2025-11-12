#include <bits/stdc++.h>
using namespace std;
int u[100005],v[100005],w[10000];
vector<int> q[100005];
vector<int> cf[100005];
int c[15][1005];
int vis[100005];
int max_cost = -1;
int dfs(int u, int sheng, int m, int cost){
	vis[u] = 1;
	if (sheng == 0){
		max_cost = min(cost,max_cost);
		return cost;
	}if (cost >= max_cost){
		return 0;
	}
	for(int i = 1; i <= m;i++){
		if (!vis[q[u][i]]){
			dfs(i, sheng - 1, m, q[u][i] + cf[i]);
		}
	} 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		q[u[i]].push_back(v[i]);
		q[v[i]].push_back(u[i]);
		cf[u[i]].push_back(w[i]);
		cf[v[i]].push_back(w[i]);
	}
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= n; i++){
			cin >> c[i][j];
		}
	}
	dfs(1,n,m, 0);
	return 0;
}
