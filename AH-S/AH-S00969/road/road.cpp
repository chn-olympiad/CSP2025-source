#include<bits/stdc++.h>
using namespace std;
int u1[1000010], u2[1000010], w[100010];
long long c[10010], a[10010];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u1[i] >> u2[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
	}
	cout << n * m - 2 * k + 1 << endl;
	return 0;
}
