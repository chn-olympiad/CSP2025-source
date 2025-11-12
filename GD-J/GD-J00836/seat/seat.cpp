#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;

const int N = 103;

int a[N], vis[13][13]; 

bool cmp (int x, int y) {
	return x > y;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf ("%d", &a[i]);
	int x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n; i++) vis[i][0] = vis[i][m + 1] = 1;
	for (int j = 1; j <= m; j++) vis[0][j] = vis[n + 1][j] = 1;
	int xx = 1, yy = 1, cnt = 1;
	while (true) {
		vis[xx][yy] = 1;
		if (a[cnt] == x) {
			printf("%d %d\n", yy, xx);
			return 0;
		}
		++cnt;
		if (!vis[xx + 1][yy]) {
			++xx;
			continue;
		}
		if (!vis[xx - 1][yy]) {
			--xx;
			continue;
		}
		++yy;
	}
}
