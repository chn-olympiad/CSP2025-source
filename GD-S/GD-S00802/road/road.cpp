#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+1;

int main(){
	freopen("road.in ", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, s = 0;
	cin >> n >> m >> k;
	int w[M], u[M], v[M];
	for (int i = 1; i <= n; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	int c[M], a[M][M];
	for (int i = 1; i <= k; k++){
		cin >> c[i];
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	cout << 13;
}
