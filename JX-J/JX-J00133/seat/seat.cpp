#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int c[20][20];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int g = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 1;
	int x = 1, y = 1;
	while (cnt <= n * n) {
		c[x][y] = a[cnt];
		if (a[cnt] == g) {
			printf("%d %d\n", y, x);
			break;
		}
		if (y % 2 == 1 && x < n) {
			x++;
		}else if (y % 2 == 1 && x == n) {
			y++;
		}else if (y % 2 == 0 && x > 1) {
			x--;
		}else if (y % 2 == 0 && x == 1) {
			y++;
		}
		cnt++;
	}
	return 0;
}
