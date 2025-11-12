#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
long long g[N][N];
long long r[13][N];
int c[20];
int f[20];
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j){
				continue;
			}
			g[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= m; i++){
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u][v] = w;
		g[v][u] = w;
	}
	
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n ;j++){
			scanf("%lld",&r[i][j]);
			if(r[i][j] == 0){
				f[i] = j;
			}
		}
	}
	for(int i = 1; i <= k; i++){
		if(f[i] == 0){
			continue;
		}
		for(int j = 1; j <= n; j++){
			if(f[i] == j){
				continue;
			}
			g[f[i]][j] = min(g[f[i]][j],r[i][j]);
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n ;i++){
			for(int j = 1; j <= n; j++){
				if(i == j || i == k || j == k){
					continue;
				}
				if(g[i][j] >= g[i][k] + g[k][j]){
					g[i][j] = g[i][k] + g[k][j];
				}	
			}
		}
	}
	long long ans = 1e18;
	for(int i = 1; i <= n; i++){
		long long t = 0;
		for(int j = 1; j <= n; j++){
			t += g[i][j];
		}
		ans = min(t,ans);
	}
	cout << ans << endl;
	return 0;
}

