#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000010], v[1000010], w[1000010], c[15], a[15][10010];
int graph[10020][10020];
int sum, maxx[10020], maxidx[10020], maxidy[10020];
bool smallTree(int ph[][10020], int x, int y) {
	bool flag = false;
	ph[m][n] = 0;
	ph[n][m] = 0;
	for(int i = 1; i <= n+k; i++) {
		flag = false;
		for(int j =1; j <= n+k; j++) {
			if(ph[i][j]) flag = true;
		}
		if(!flag) return false; 
	}
	return true;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		a[u[i]][v[i]] = w[i];
		a[v[i]][u[i]] = w[i];
		
	}
	for(int j = 1; j <= k; j++) {
		cin >> c[j];
		for(int i = 1; i <= n; i++) {
			cin >> a[j][i];
			graph[i][j+m] = a[j][i]+c[j];
			graph[j+m][i] = a[j][i]+c[j];
		}
	}
	
	for(int i = 1; i <= n+k; i++) {
		
	}
//	for(int i = 1; i <= m; i++) {
//		for(int j = 1; j <= k; j++) {
//			w[i] = min(w[i], a[j][u[i]]+a[j][v[i]]+c[j]);
//		}
//	}
//	for(int i = 1; i <= m; i++) {
//		sum += w[i];
//	}
//	cout << sum;
	return 0;
}

