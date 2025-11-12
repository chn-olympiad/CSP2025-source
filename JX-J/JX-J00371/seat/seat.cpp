#include <bits/stdc++.h>
using namespace std;
bool cmp(int c, int d) {
	return c > d;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int s = n * m;
	int a[s];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = a[0];
	sort(a, a + s, cmp);
	int x = 1, y = 1;
	for (int i = 0; i < n * m; i++) {
		if (a[i] == k) {
			cout << y << " " << x;
			return 0;
		}
		if (y % 2 == 1) {
			if (x < n) {
				x++;
			} else {
				y++;
				x = n;
			}
		} else {
			if (x > 1) {
				x--;
			} else {
				y++;
				x = 1;
			}
		}
	}
 	return 0;
}
