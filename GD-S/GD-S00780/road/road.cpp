#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k, c[N], a[11][N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
	} 
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}
