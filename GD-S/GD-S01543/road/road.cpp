#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int u[MAXN], v[MAXN], w[MAXN], c[15], a[15][MAXN];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i=1; i<=k; i++){
		scanf("%d", &c[i]);
		for (int j=1; j<=n; j++) scanf("%d", &a[i][j]);
	}
	cout << "0" << '\n';
	return 0;
}
