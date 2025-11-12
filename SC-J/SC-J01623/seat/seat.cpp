#include <bits/stdc++.h>
using namespace std;

const int N = 109;
int a[N], n, m, R;

void dfs(int x, int y, int fx, int id) {
	if (x == 0) x = 1, y++, fx = 1;
	if (x == n + 1) x = n, y++, fx = -1;
	if (a[id] == R) {
		printf("%d %d\n", y, x);
		exit(0);
	}
	dfs(x + fx, y, fx, id + 1);
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	R = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	dfs(1, 1, 1, 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}