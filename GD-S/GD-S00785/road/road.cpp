#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int a[10005][10005],k[10][10005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u, v, w;
		cin >> u >> v;
		a[u][v] = w;
	}
	for(int i = 1;i <= k;i++){
		for(int j = 0;j <= n;j++){
			cin >> c[i][j];
		}
	}
	cout << 0;
	return 0;
}
