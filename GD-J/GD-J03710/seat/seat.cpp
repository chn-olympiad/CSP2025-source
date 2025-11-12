#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
int a[N * N];
int c[N * N];
int b[N][N];

void dfs(int x, int y, int step, int way) {
	if (x <= 0) {
		dfs(x + 1, y + 1, step, 1 - way);
		return;
	} else if (x > n) {
		dfs(x - 1, y + 1, step, 1 - way);
		return;
	} else if (step > n * m) {
		return;
	}
	if (c[step] == a[1]) {
		cout << y << " " << x;
		return;
	}
	b[x][y] = c[step];
	if (!way) dfs(x + 1, y, step + 1, way);
	else dfs(x - 1, y, step + 1, way);
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	sort(c + 1, c + n * m + 1, greater<int>());
	dfs(1, 1, 1, 0);
	return 0;
} 
