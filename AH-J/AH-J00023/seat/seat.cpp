#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 12;
int n, m, a[N * N], snk[N][N], ansx, ansy, fst, p, dx, dy, nx, ny;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	fst = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	p = 1, dx = 1, dy = 0, nx = 1, ny = 1;
	snk[1][1] = a[1];
	while (p + 1 <= n * m) {
		p++;
		if (nx == n) {
			if (dx == 1 && dy == 0) {
				dx = 0, dy = 1;
			} else if (dx == 0 && dy == 1) {
				dx = -1, dy = 0;
			}
		} else if (nx == 1) {
			if (dx == -1 && dy == 0) {
				dx = 0, dy = 1;
			} else if (dx == 0 && dy == 1) {
				dx = 1, dy = 0;
			}
		}
		nx += dx, ny += dy;
//		printf("%d %d\n", nx, ny);
		snk[nx][ny] = a[p];
		if (a[p] == fst) {
			ansx = nx, ansy = ny;
		}
	}
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d ", snk[i][j]);
//		}
//		puts("");
//	}
	printf("%d %d", ansy, ansx);
	return 0;
}

