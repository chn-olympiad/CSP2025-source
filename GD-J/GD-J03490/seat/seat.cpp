#include <bits/stdc++.h>
using namespace std;

const int d[] = {1, -1};

int n, m, a[200];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	int s = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int x = 1, y = 1, t = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			printf("%d %d\n", y, x);
			break;
		}
		x += d[t];
		if (x < 1 || x > n) {
			x -= d[t];
			t ^= 1;
			y += 1;
		}
	}
	return 0;
}