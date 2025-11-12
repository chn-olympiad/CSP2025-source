#include<bits/stdc++.h>
using namespace std;
struct Node{
	int h, t;
};
const int W = 1e5 + 5;
long long n, m, k, a[W], ans = LLONG_MAX, v[W];
vector<Node> vt[W];
void dfs(long long x, int y, int z, int q){
	if(y == z + n){
		ans = min(ans, x);
		return ;
	}
	if(v[q]) return ;
	v[q] = 1;
	a[q] = x;
	for(int i = 0; i < vt[q].size(); i++){
		if(vt[q][i].h > n){
			dfs(x + vt[q][i].t, y + 1, z + 1, vt[q][i].h);
		}else{
			dfs(x + vt[q][i].t, y + 1, z, vt[q][i].h);
		}
	}
	v[q] = 0;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	fill(a + 1, a + 1 + k + m, 1e16);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		vt[v].push_back({u, w});
		vt[u].push_back({v, w});
	}
	for(int i = 1; i <= k; i++){
		int p;
		cin >> p;
		for(int j = 1; j <= m; j++){
			int w;
			cin >>w;
			w += p;
			vt[m + i].push_back({j, w});
			vt[j].push_back({m + i, w});
		}
	}
	dfs(0, 1, 0, 1);
	cout << ans;
	return 0;
}
