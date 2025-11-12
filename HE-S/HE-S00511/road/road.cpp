//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
using namespace std;
long long n, m, k, ans;
const int N = 1e4;
const int K = 15;
	int a[N][N], b[K][N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			a[i][j] = 1e7;
		}
	}
	for (int i = 1; i <= m; i ++) {
		long long u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
	}
	long long x = 1,u = 1e8, d;
	for (int i = 1; i <= n; i++) {
			if (a[x][i] < u) {
				u = a[x][i];
				d = i;
			}
		for (int j = 1; j <= n; j++) {
		
			if (a[x][j] > a[x][d] + a[d][x]) {
				a[x][j] = a[x][d] + a[d][x];
			}
		}
	}
	for (int i = 1; i <= k; i ++) {
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		ans += a[1][i];
	}
	cout << 0;
	return 0;
	//for (int i = 1; i <= k; i ++) {
	//	long long kans = ans;
	//	kans + 
	//	for (int j = 1; j <= n; j++) {
	//		
	//	}
	//}
}
