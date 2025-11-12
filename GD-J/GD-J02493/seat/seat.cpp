#include <bits/stdc++.h>

using namespace std;
int n, m, cnt;
int a[105], b[12][12];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cnt = n * m;
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	int x = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				b[j][i] = a[cnt--];
				if (a[cnt + 1] == x) {
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				b[j][i] = a[cnt--];
				if (a[cnt + 1] == x) {
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
