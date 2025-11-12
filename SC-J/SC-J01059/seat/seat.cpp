#include <bits/stdc++.h>
using namespace std;
const int N = 103;
int n, m, a[N] = {}, score, cur, cnt = 0;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	score = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	cur = lower_bound(a + 1, a + 1 + n * m, score, greater<int>()) - a;
//	printf("%d\n", cur);
//	for (int i = 1; i <= n * m; i++) {
//		printf("%d ", a[i]);
//	}
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= m; j++) {
				if (++cnt == cur) {
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		}
		else {
			for (int j = m; j >= 1; j--) {
				if (++cnt == cur) {
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		}
	}
	return 0;
}