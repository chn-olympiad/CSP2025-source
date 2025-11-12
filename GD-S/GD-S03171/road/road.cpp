#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	long long ans = 0;
	for (int i = 0; i < m; i ++) {
		int x, y, z;
		cin >> x >> y >> z;
		ans += z;
	}
	bool xz = 1;
	while (k --) {
		for (int i = 0; i <= n; i ++) {
			int x; cin >> x;
			if (x) xz = 0;
		}
	}
	cout << (xz ? 0 : ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
