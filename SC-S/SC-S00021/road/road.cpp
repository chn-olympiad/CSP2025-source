#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, k;
int c[15];
int a[15][maxn];
int dis[maxn][maxn];
int h[maxn*maxn / 2 + 2];
int ans;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;i++){
			dis[i][j]=0x3f,dis[j][i]=0x3f;
			if(i==j)dis[i][j]=0;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int l = 1; l <= n; l++) {
				dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int l = 1; l <= k; l++)dis[i][j] = min(dis[i][j], c[l] + a[l][i] + a[l][j]);
			dis[j][i] = dis[i][j];
		}
	}
	int t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i - 1; j++) {
			h[++t] = dis[i][j];
		}
	}
	sort(h + 1, h + t + 1);
	cout << h[1]+h[2]+h[3] << '\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/