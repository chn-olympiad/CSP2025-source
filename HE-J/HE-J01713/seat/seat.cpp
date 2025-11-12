#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
bool cmp(int c, int b) {
	return c > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%d", &a[0]);
	int r = a[0];
	for (int i = 1; i < n * m; i++) scanf("%d", &a[i]);
	sort(a, a + n * m, cmp);
	int x = 1, y = 1, t = 1;
	for (int i = 0; i < n * m; i++) {
		if (a[i] == r) {
			printf("%d %d", y, x);
			return 0;
		}
		if (x + t > n || x + t <= 0) {
			t = -1 * t;
			y++;
		} else x += t;
	}
	return 0;
}
