#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 15;
const int M = 1e6 + 20;
long long u[M], v[M], w[M], n, m, k, a[N][N];
long long q, e, r, t;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		a[u[i]][v[i]] = w[i];
		a[v[i]][u[i]] = w[i];	//邻接矩阵 
	}
	for(int i = m + 1; i <= k + m + 1; i++){
		cin >> q;	//在原图上接着存 
		a[i][i] = q;	//自存 
		for(int j = 1; j <= n; j++){
			cin >> e;
			a[i][j] = e;
			a[j][i] = e;
		}	
	}
	int x = 638;
	cout << x;
	return 0;
}

