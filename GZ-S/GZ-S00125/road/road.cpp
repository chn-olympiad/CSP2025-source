//GZ-S00125 贵阳市南明区李端棻中学 姜铭灿 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <array>
using namespace std;
const int MAXN = 2e4 + 5; 
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, ts[MAXN];
long long dis[MAXN], val[MAXN], cst[MAXN];

struct Edge{
	int v, w;
}; vector <Edge> adj[MAXN];

bool vis[MAXN];
long long prim(){
	priority_queue < array <long long, 3> > pq;
	memset(dis, INF, sizeof(dis));
	dis[1] = 0, pq.push({-dis[1], 1, 0});
	long long ret = 0, cnt = 0;
	while(cnt < n){
		int u = pq.top()[1], f = pq.top()[2];
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1, cnt += (u <= n), ret += dis[u] + val[u], ts[f]++, cst[u] += dis[u], cst[f] += dis[u];
		for(Edge e : adj[u]){
			long long v = e.v, w = e.w;
			if(dis[v] > w) dis[v] = w, pq.push({-dis[v] - val[v], v, u});
		}
	}
	return ret;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, u, v, w; i <= m; i++){
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w}), adj[v].push_back({u, w});
	}
	for(int i = 1, c; i <= k; i++){
		cin >> val[n + i];
		for(int v = 1, u = n + i, w; v <= n; v++) cin >> w, adj[v].push_back({u, w}), adj[u].push_back({v, w});
	}
	long long ans = prim();
	for(int i = 1; i <= k; i++)
		if(ts[n + i] <= 1) ans -= cst[n + i];
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
