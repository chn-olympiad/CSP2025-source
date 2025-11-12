#include <bits/stdc++.h>

using namespace std;

int n, m;
int R, a[107];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", & n, & m);
	for (int i = 1; i <= n * m; ++ i) {
		scanf("%d", & a[i]);
	}
	R = a[1];
	sort(a + 1, a + 1 + n * m, greater < int > ());
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if ((i & 1) && a[(i - 1) * n + j] == R) {
				printf("%d %d\n", i, j);
				puts("");
				return 0;
			}
			if ((! (i & 1)) && a[i * n - j + 1] == R) {
				printf("%d %d\n", i, j);
				puts("");
				return 0;
			}
		}
	}
	return 0;
}
