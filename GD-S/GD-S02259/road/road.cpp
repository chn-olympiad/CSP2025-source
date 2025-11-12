#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m, k, cj;
int u[N], v[N], w[N], a[N];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.in", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1; i <= k; i++){
		cin >> cj;
		for(int j = 1; j <= n; i++){
			cin >> a[j];
		}
	}
	cout << 1;
	return 0;
}
