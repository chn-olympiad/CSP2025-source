#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
struct node {
	int v, i;
	bool operator < (const node cmp) const {
		return v > cmp.v;
	}
} a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i].v, a[i].i = i;
	sort(a + 1, a + n * m + 1);
	int w = -1;
	for (int i = 1; i <= n * m; ++i) {
		if (a[i].i == 1) {
			w = i;
			break;
		}
	}
	int x = 1, y = 1, c = 1;
	for (int i = 2; i <= w; ++i) {
		y += c;
		if (y == n + 1 || y == 0) {
			if (x & 1) {
				y = n;
				c = -1;
				++x;
			} else {
				y = 1;
				c = 1;
				++x;
			}
		}
	}
	cout << x << " " << y;
	return 0;
}