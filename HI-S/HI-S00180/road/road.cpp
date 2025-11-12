#include<bits/stdc++.h>
using namespace std;
//RP++
//I L ASCII(728383) F
//except 8pts
const int N = 1e4 + 100;
int n, m, k;
int c[N], a[N][N];
int fa[N];
struct edge{
	int u, v, w;
	bool operator<(const edge b)const{
		return w > b.w;
	}
};
priority_queue<edge> g;

int find(int p){
	return fa[p] == p ? p : fa[p] = find(fa[p]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g.push({u, v, w});
	}
	for(int j = 1; j < k; j++){
		cin >> c[j];
		for(int i = 1; i <= n; i++){
			cin >> a[j][i];
		}
		for(int u = 1; u <= n; u++){
			for(int v = 1; v <= n; v++){
				if(u != v){
					g.push({u, v, a[j][u] + a[j][v]});
				}
			} 
		}
	}
	int ans = 0;
	for(int i = 0; i < n-1; i++){
		edge e = g.top();
		while(find(e.u) == find(e.v)){
			g.pop();
			e = g.top();
		}
		fa[fa[e.u]] = fa[e.v];
		ans += e.w;
	}
	cout << ans; 
	return 0;
}
/*
4 5 2

1 2 3
1 3 4
3 2 5
4 3 2
2 4 1

0 1 2 3 4
0 4 3 2 1
*/
