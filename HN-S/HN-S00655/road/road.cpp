#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, M = 1e5 + 10;

int u[N], v[N], w[N];
int c[20];
int a[M];
int f[N];

int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	 
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++) cin >> u[i] >> v[i] >> w[i];
	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		
		for (int j = 1; j <= n; j++) cin >> a[j];
	}
	
	f[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			f[j] = f[i - 1] + min (f[i - 1], a[j - v[i]] + w[i]);
		}
	}
	
	cout << f[n];
		
	return 0;
}
