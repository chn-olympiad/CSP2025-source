#include <bits/stdc++.h>

using namespace std;

const int N = 105;
bool vis[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int c, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			vis[x] = true;
			if (i == 1 and j == 1)
				c = x;
		}
	} for (int i = 100; i >= 1; i--) {
		if (i == c) break;
		if (vis[i]) ans++;
	} cout << ans / n + 1 << ' ';
	if ((ans / n) % 2 == 0) 
		cout << ans % n + 1 << endl;
	else
		cout << n - ans % n << endl;
	return 0;
}
