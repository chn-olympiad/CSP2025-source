// GZ-S00180 黔南布依族苗族自治州都匀第一中学 张铮瀚
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

#define maxn 10003

int g[maxn][maxn];
int a[maxn];
struct node{
	int u,cost;
	unordered_set<int> vis;
	bool operator <(const node& other) const {
		return cost > other.cost;
	};
};

priority_queue<node> q;
int n,m,k;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
		
	memset(g, -1, sizeof(g));
	cin >> n >> m >> k;
	int u,v,w;
	for(int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	for(int i = 1; i <= k; ++i) {
		int cost,dest;
		cin >> cost;
		
		for(int j = 1; j <= n; ++j) {
			cin >> a[j];			
		}
		cost += a[i];
		for(int k = 1; k <= n; ++k) {
			g[i][k] = min(g[i][k], a[i] + cost);
		}
	}
	
	unordered_set<int> path0;
	path0.insert(1);
	q.push((node) {1,0, path0});
	
	while(!q.empty()) {
		node u = q.top(); q.pop();
		if(u.vis.size() == n) {
			cout << u.cost << endl;
			return 0;
		}
		
		for(int i = 1; i <= n; ++i) {
			if(i == u.u) continue;
			if(g[u.u][i] == -1) continue;	
			if(u.vis.count(i)) continue;
			int we = g[u.u][i];
			
			node ne;
			
			ne.u = i; 
			ne.cost = u.cost + g[u.u][i];
			ne.vis = u.vis;
			ne.vis.push_back(i);
			
			q.push(ne);
		}
	}
	
	cout << -1 << endl;
	return 0;
} 
