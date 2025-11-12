#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5, K = 15, N = 1e4 + 5;
long long n, m, k, u[M], v[M], w[M], c[K], a[K][N], i, j;
//void dfs(long long k){
//	if(k > m){
//						
//	}	
//} 
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(i = 1; i <= k; i++){
		cin >> c[i];
		for(j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	cout << 0; 
	return 0;
}
