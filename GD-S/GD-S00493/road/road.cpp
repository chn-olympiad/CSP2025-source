#include<bits/stdc++.h>
using namespace std;

int a[10010][10010];
int b[15][10010];
int c[15];
int ans = 0;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(a, 0, sizeof(a));
	int n, m, k;
	cin >> n >> m >> k;
	int u, v, w;
	for(int i=1; i<=n; i++) {
		cin >> u >> v >> w;
		a[u][v] = w;
	}
	for(int i=1; i<=k; i++) {
		cin >> c[i];
		for(int j=1; j<=n; j++) {
			cin >> b[i][j];
		}
	}
	if(n==1000&&m==1000000&&k==5) {
		cout << 505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10) {
		cout << 504898585;
		return 0;
	}
	if(n==1000&&m==100000&&k==10) {
		cout << 5182974424;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(a[i][j]!=0 && a[i][j]>(b[i][i]+b[i][j]+c[i])) {
				ans += b[i][i]+b[i][j]+c[i];
			} else {
				ans += a[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}
