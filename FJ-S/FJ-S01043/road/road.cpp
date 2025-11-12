#include<bits/stdc++.h>

#define int long long

using namespace std;

int n, m, k;

int c[15];
int a[15][10004];

int vis[10024];
int cnt;

struct node{
	int u, v, w;
	bool operator < (const node &other) const {
		int otherc = 0;
		int wc = 0;
		if(v > n && vis[v] == 0){
			wc = c[v - n];
		}
		if(other.v > n && vis[other.v] == 0){
			otherc = c[other.v - n];
		}
		return other.w + otherc < w + wc;
	}
};
vector<node> edge[10024];
int cedge[15];
int clink[15];
priority_queue<node> pq;

signed main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin>> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin>> u >> v >> w;
		edge[u].push_back({u, v, w});
		edge[v].push_back({v, u, w});
	}
	
	for(int i = 1; i <= k; i++){
		cin>> c[i];
		for(int j = 1; j <= n; j++){
			cin>> a[i][j];
			edge[j].push_back({j, n + i, a[i][j]});
			edge[n + i].push_back({n + i, j, a[i][j]});
		}
	}
	
	vis[1] = 1;
	cnt = 1;
	
	for(int i = 0; i < edge[1].size(); i++){
		pq.push(edge[1][i]);
	}
	int ans = 0;
	while(cnt < n + k){
		node x = pq.top();
		pq.pop();
		if(vis[x.v]){
			continue;
		}
		
		ans += x.w;
		if(x.v > n){
			ans += c[x.v - n];
			cedge[x.v - n]++;
			clink[x.v - n] = x.u;
		}
		if(x.u > n){
			cedge[x.u - n]++;
			clink[x.u - n] = x.v;
		}
		vis[x.v] = 1;
		cnt ++;
		
		for(int i = 0; i < edge[x.v].size(); i++){
			int vv = edge[x.v][i].v;
			if(vis[vv] == 0){
				pq.push(edge[x.v][i]);
			}
		}
	}
	
	for(int i = 1; i <= k; i++){
		if(cedge[i] == 1){
			ans -= c[i];
			ans -= a[i][clink[i]];
		}
	}
	
	cout<< ans << "\n";
	
	return 0;
} 
