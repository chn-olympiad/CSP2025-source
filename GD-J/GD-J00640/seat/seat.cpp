#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int a[N * N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, rnk = 0;
	cin >> n >> m >> a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
		rnk += (a[i] > a[1]);
	}
	cout << rnk / n + 1 << ' ' << ((rnk / n + 1) % 2 == 0 ? ((rnk + 1) % n == 0 ? n : n - (rnk + 1) % n + 1) : ((rnk + 1) % n == 0 ? n : (rnk + 1) % n));
	return 0;
}
