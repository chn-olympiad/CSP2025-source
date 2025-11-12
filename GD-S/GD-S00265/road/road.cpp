#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using LL = long long;

struct node{
	int v, w;
};

int n, m, k, vis[N], a[21][N], c[21], visc[21][N];
LL minn = 1e18;
vector<node> vt[N];

int bfs(int s){
	queue<pair<int, int>> q;
	q.push({s, 0});
	vis[s] = 1;
	
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		
		int u = p.first;
		int w = p.second;
		bool f = 1;
		
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){
				f = 0;
				break;
			}
		}
		
		if(f){
			return w;
			break;
		}
		
		for(auto x: vt[u]){
			
			int minw = x.w;
			
			if(vis[x.v]) continue;
			for(int i = 1; i <= k; ++i){
				int t = c[i];
				int uu = a[i][u];
				int vv = a[i][x.v];
				
				if(visc[i][u]) t = 0, uu = 0;
				if(visc[i][x.v]) t = 0, vv = 0;
				minw = min(minw, t + uu + vv);
			}
			
			vis[x.v] = 1;
			
			q.push({x.v, minw + w});
		}
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		vt[u].push_back({v, w});
		vt[v].push_back({u, w});
	}
	for(int i = 1; i <= k; ++i){
		cin >> c[i];
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	
	for(int i = 1; i <= n; ++i){
		memset(vis, false, sizeof(vis));
		memset(visc, false, sizeof(visc));
		
		LL p = bfs(i);
		minn = min(p, minn);
	}
	
	cout << minn;
	
	return 0;
}
