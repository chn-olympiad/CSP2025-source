#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10, maxm = 1e6 + 10;
struct node{
	int v, w;
};
vector<node> road[maxn];
int tot;
bool vis[maxn];
int ans;
int t(int p, int fa){
	for(int i = 0; i < road[p].size(); i++);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		node a;
		a.v = v;a.w = w;
		road[u].push_back(a);
		a.v = u;
		road[v].push_back(a);
	}
	for(int i = 1; i < n; i++){
		
	}
	return 0;
}
