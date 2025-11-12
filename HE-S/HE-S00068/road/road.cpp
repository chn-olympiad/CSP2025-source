#include<bits/stdc++.h>
using namespace std;

int n, m, k, t = 1, ch, sum;
int v[1000010][5];
int a[20][10010];
int tu[200000010];
int d[10010][10010];

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> v[i][1] >> v[i][2] >> v[i][3];
		d[v[i][1]][v[i][2]] = v[i][3];
	}
	for (int i = 1; i <= k; i ++) {
		for (int j = 0; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i < n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			for (int x = 1; x <= k; x ++) {
				if (a[x][0] + a[x][i] + a[x][j] <= d[i][j]) {
					d[i][j] = a[x][0] + a[x][i] + a[x][j];
				}
			}
			tu[t] =d[i][j];
			t ++; 
		}
	}
	for (int j = 1; j < t; j ++) {
		for (int x = t - 1; x > j; x --) {
			if (tu[x] < tu[x - 1]) {
				ch = tu[x];
				tu[x] = tu[x - 1];
				tu[x - 1] = ch;			
			}
		}
	}
	for (int i = 1; i <= t - 1; i ++) {
		sum += tu[i];
	}
	cout << sum;
//	cout << 0;
	return 0;
}
