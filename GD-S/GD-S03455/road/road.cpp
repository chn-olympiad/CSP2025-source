#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;;
int n, m, k, ans;
bool vis[N];
struct edge{
	int v, c;
};
vector <edge> g[N], imc[N];
int im[N];
bool operator < (edge l, edge r){
	return l.c > r.c;
}
priority_queue <edge> q;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++){
		cin >> im[i];
		for(int j = 1; j <= n; j++){
			int v, c;
			scanf("%d%d", &v, &c);
			imc[i].push_back({v, c});
		}
	}
	for(int i = 0; i < g[1].size(); i++){
		q.push({g[1][i]});
	}
	int cnt = 1;
	vis[1] = 1; 
	while(cnt < n){
		edge head = q.top();
		q.pop();
		int u = head.v;
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		ans += head.c;
		cnt++;
		for(int i = 0; i < g[u].size(); i++){
			q.push(g[u][i]);
		}
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
