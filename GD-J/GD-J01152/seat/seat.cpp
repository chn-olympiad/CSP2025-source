#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 1005;

int a[N]; 

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) cin >> a[i];
	int x = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == x) {
			x = i; break;
		}
	}
//	cout << x << endl;
	int c = (x + n - 1) / n;
	int r = (x - 1) % n + 1;
	if (c % 2 == 0) r = n - r + 1;
	cout << c << ' ' << r;
	return 0;
}

