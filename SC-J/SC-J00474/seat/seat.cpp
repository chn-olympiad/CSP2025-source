#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10000];
bool cmt (int x, int y) {
	return x > y;
}
int h = 1, l = 1;
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sort (a + 2, a + 1 + n * m, cmt);
	for (int i = 2; i <= n * m; i++) {
		if (a[1] > a[i]) {
			cout << l << " " << h;
			return 0;
		}
		if (l % 2 == 1) {
			h++;
			if (h == n + 1) {
				h = n;
				l++;
			}
		}
		else {
			h--;
			if (h == 0) {
				h = 1;
				l++;
			}
		}
	}
	cout << m << " " << n;
	return 0;
}