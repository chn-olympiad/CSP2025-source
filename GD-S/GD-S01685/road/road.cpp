#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
struct edge{
	int u, v, w;
	bool operator < (const edge &x) const{
		return w > x.w;
	}
};
priority_queue<edge> g;
int dis[20][N];
bool vis[20];
int fa[N];
int c[20];
int n, m, k;
int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
//50pts
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int u, v, w;
	for(int i = 1;i <= m;i ++){
		scanf("%d%d%d", &u, &v, &w);
		g.push({u, v, w});
	}	
	int cnt = 0;
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		cnt ++;
		for(int j = 1;j <= n;j ++){
			scanf("%d", &w);
			g.push({cnt + n, j, w + c[i]});
			dis[cnt][j] = w;
		}
	}
	for(int i = 1;i <= n + cnt;i ++) fa[i] = i;
	long long ans = 0, cc = 0;
	while(!g.empty()){
		u = g.top().u, v = g.top().v, w = g.top().w;
		g.pop();
		if(find(u) == find(v)){
			continue;
		}
		if(u > n && v > n) continue;
		if(u > n && !vis[u]){
			vis[u] = 1;
			for(int i = 1;i <= n;i ++){
				g.push({u, i, dis[u - n][i]});
			}
		}
		ans += w;
		fa[find(u)] = find(v);
		cc++;
		if(cc == n + cnt - 1) break;
	}
	cout << ans;
	return 0;
}
