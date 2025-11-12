#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//1~n
const ll MAXN = 1e4+5;
ll n, u, v, w, m, k, ans, minq = 1e9+5;
ll G[MAXN][MAXN];
ll g[MAXN][MAXN];//确认边是否被选中
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			G[i][j] = minq;
		}
	}
	cin >> n >> m >> k;
	for(ll i = 0; i < m; i++){
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}
	if(k == 0){
		ll maxq = -1;
		for(ll i = 1; i <= n; i++){
			ll miny;
			minq = 1e9+5;
			for(ll j = 1; j <= n; j++){
				if(G[i][j] < minq && g[i][j]==false && i!=j){
					miny = j;
					minq = G[i][j];
				}
			}
			maxq = max(maxq, G[i][miny]);
			ans+=G[i][miny];
			g[i][miny] = true;
			g[miny][i] = true;
		}
		cout << ans-maxq;
	}
	else{
		cout << 0;
	}
	return 0;  
}
