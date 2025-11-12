#include <bits/stdc++.h>
using namespace std;
long long a[10010][10010], b[10010];
vector<long long> c;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(a, 0x3f, sizeof(a));
	long long n, m, k, u, v, w, x;
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; i++){
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}
	for (long long i = 1; i <= k; i++){
		cin >> x;
		for (long long j = 1; j <= n; j++){
			cin >> b[j];
			for (long long k = 1; k < j; k++){
				a[k][j] = min(a[k][j], x+b[j]+b[k]);
			}
		}
	}
	for (long long i = 1; i <= n; i++){
		for (long long j = i+1; j <= n; j++){
			if (a[i][j] != 0x3f3f3f3f) c.push_back(a[i][j]);
		}
	}
	sort(c.begin(), c.end());
	long long ans = 0;
	for (long long i = 0; i+1 < n; i++) ans += c[i];
	cout << ans;
	return 0;
}
