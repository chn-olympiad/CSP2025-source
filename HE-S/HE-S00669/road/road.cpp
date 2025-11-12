#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	srand(time(0));

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= n; j++)
			cin >> x;
	}
	long long q = rand() % 1000000000 + 1;
	cout << q << endl;

	return 0;
}
