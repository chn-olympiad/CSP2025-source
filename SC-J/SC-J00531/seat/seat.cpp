#include <bits/stdc++.h>
using namespace std;
int grad[110];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, mine;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n * m; i++) scanf("%d", grad + i);
	mine = grad[0];
	sort(grad, grad + n * m, cmp);
	for (int i = 0; i < n * m; i++) if (grad[i] == mine) {
		int x = i / n + 1, y = x % 2 ? (i % n + 1) : (n - (i % n));
		printf("%d %d\n", x, y);
		break;
	}
	return 0;
}