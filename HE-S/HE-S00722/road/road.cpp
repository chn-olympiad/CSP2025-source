#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	long long ans = 0;
	for (int i = 1, a, b, c; i <= m; i++) {
		cin >> a >> b >> c;
		ans += c;
	}
	cout << ans << endl;
	return 0;
} 
