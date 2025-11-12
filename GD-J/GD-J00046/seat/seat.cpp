#include <bits/stdc++.h>
using namespace std;
int a[105], b[15][15];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, f, cnt = 1;
	scanf("%d%d%d", &n, &m, &f);
	a[1] = f;
	for (int i = 2; i <= n * m; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) b[j][i] = a[cnt++];
		} else {
			for (int j = n; j > 0; j--) b[j][i] = a[cnt++];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == f) {
				printf("%d %d", j, i);
				return 0;
			} 
		}
	}
	return 0;
}
