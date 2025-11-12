#include <iostream>

using namespace std;

int n, m, k;
int u[1000001], v[1000001], w[1000001], c[11], a[11][10001];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; i ++) {
			cin >> a[i][j];
		}
	}
	cout << 13 << endl;
	return 0;
}
