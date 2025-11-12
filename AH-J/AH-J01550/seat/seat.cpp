#include <bits/stdc++.h>

using namespace std;

int n, m, a[1005], rnk = 1, r, c;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] > a[1])	rnk++;
	}
	
	c = (rnk - 1) / n + 1;
	if (c % 2 == 1) {
		r = (rnk - 1) % n + 1;
	} else if (c % 2 == 0) {
		r = n - (rnk - 1) % n;
	}
	
	cout << c << " " << r << "\n";
	
	return 0;
}
