#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> a(n * m + 10);
	a[0] = 114514;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a.begin(), a.end(), cmp);
	int x;
	int Le = 1, Ri = a.size() - 1;
	while (Le <= Ri) {
		int mid = (Le + Ri) / 2;
		if (a[mid] < r) {
			Ri = mid;
		} else if (a[mid] > r) {
			Le = mid + 1;
		} else {
			x = mid;
			break;
		}
	}
	int q = x % (2 * n);
	int s = x / (2 * n);
	cout << s * 2 + 1 + int(q > n) << " ";
	if (q > n) {
		cout << 2 * n - q + 1;
	} else {
		cout << q;
	}
	return 0;
}