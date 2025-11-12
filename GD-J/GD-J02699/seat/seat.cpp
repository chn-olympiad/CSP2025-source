#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m, a[N]; 

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i];
	}
	int v = a[1];
	sort(a + 1, a + n*m + 1, greater<int>());
	int x = 0, y = 1, f = 1;
	for (int i = 1; i <= n*m; i++) {
		x += f;
		if (x == n + 1 || x == 0) {
			x -= f;
			y++, f = -f;
		}
		if (a[i] == v) {
			cout << y << " " << x << "\n";
			return 0;
		}
	}
	return 0;
} 
