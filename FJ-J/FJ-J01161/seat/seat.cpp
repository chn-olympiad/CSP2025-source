#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m, a[N * N], num;
int x, y, flag;
int ans[N][N], ansx, ansy;
bool cmp(int numa, int numb) {
	return numa > numb;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
		if (i == 1) num = a[i];
	}
	sort(a + 1, a + n * m + 1, cmp);
	x = 1, y = 1, flag = 1;
	for (int i = 1; i <= n * m; i++) {
		ans[x][y] = a[i];
		if (flag == 1) {
			x++;
			if (x == n + 1) {
				flag = 2;
				x = n, y++;
			}
		} else {
			x--;
			if (x == 0) {
				flag = 1;
				x = 1, y++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ans[i][j] == num) {
				ansx = i;
				ansy = j;
				break;
			}
		}
	}
	printf("%d %d", ansy, ansx);
	return 0;
}
