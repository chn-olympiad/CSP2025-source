#include <bits/stdc++.h>
using namespace std;
struct ed{
	int v, w, top;
};
vector<ed> g[10005];
int n, m, k, u, v, w, c[11], a[11][10005];
int find(vector<ed> t){
	if (g[t].top == t) return t;
	return g[t].top = find(g[t].top);
}
void kruskal(){
	//不会写啊，忘了
	//送点分吧
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> u >> v >> w;
		g[u].push_back({v, w, u});
		g[v].push_back({u, w, v});
	}
	return 0;
}
