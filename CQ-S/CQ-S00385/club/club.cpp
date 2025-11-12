#include <stdio.h>
#include <stdlib.h>
int t, n, m, a[100010][3], c1, c2, c3, ans;
struct node {
	int val, mnv, top, toa, tob;
} b1[100010], b2[100010], b3[100010];
int min(int a, int b) { return a < b ? a : b; }
int cmp(const void* a, const void* b) { return ((struct node*)a) -> mnv - ((struct node*)b) -> mnv; }
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n), m = n / 2, ans = c1 = c2 = c3 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) scanf("%d", &a[i][j]);
			if (a[i][1] > a[i][2]) {
				if (a[i][1] > a[i][3]) b1[++c1].val = a[i][1], b1[c1].mnv = min(a[i][1] - a[i][2], a[i][1] - a[i][3]), b1[c1].top = a[i][1] - a[i][2] < a[i][1] - a[i][3] ? 2 : 3, b1[c1].toa = a[i][2], b1[c1].tob = a[i][3];
				else b3[++c3].val = a[i][3], b3[c3].mnv = min(a[i][3] - a[i][1], a[i][3] - a[i][2]), b3[c3].top = a[i][3] - a[i][1] < a[i][3] - a[i][2] ? 1 : 2, b3[c3].toa = a[i][1], b3[c3].tob = a[i][2];
			} else {
				if (a[i][2] > a[i][3]) b2[++c2].val = a[i][2], b2[c2].mnv = min(a[i][2] - a[i][1], a[i][2] - a[i][3]), b2[c2].top = a[i][2] - a[i][1] < a[i][2] - a[i][3] ? 1 : 3, b2[c2].toa = a[i][1], b2[c2].tob = a[i][3];
				else b3[++c3].val = a[i][3], b3[c3].mnv = min(a[i][3] - a[i][1], a[i][3] - a[i][2]), b3[c3].top = a[i][3] - a[i][1] < a[i][3] - a[i][2] ? 1 : 2, b3[c3].toa = a[i][1], b3[c3].tob = a[i][2];
			}
		}
		if (c1 > m) {
			qsort(b1 + 1, c1, sizeof b1[0], cmp);
			for (int i = 1; i <= c1 - m; i++)
				if (b1[i].top == 2) b2[++c2].val = b1[i].toa, b1[i].mnv = 2e9;
				else b3[++c3].val = b1[i].tob, b1[i].mnv = 2e9;
			qsort(b1 + 1, c1, sizeof b1[0], cmp), c1 = m;
		}
		if (c2 > m) {
			qsort(b2 + 1, c2, sizeof b2[0], cmp);
			for (int i = 1; i <= c2 - m; i++)
				if (b2[i].top == 1) b1[++c1].val = b2[i].toa, b2[i].mnv = 2e9;
				else b3[++c3].val = b2[i].tob, b2[i].mnv = 2e9;
			qsort(b2 + 1, c2, sizeof b2[0], cmp), c2 = m;
		}
		if (c3 > m) {
			qsort(b3 + 1, c3, sizeof b3[0], cmp);
			for (int i = 1; i <= c3 - m; i++)
				if (b3[i].top == 1) b1[++c1].val = b3[i].toa, b3[i].mnv = 2e9;
				else b2[++c2].val = b3[i].tob, b3[i].mnv = 2e9;
			qsort(b3 + 1, c3, sizeof b3[0], cmp), c3 = m;
		}
		for (int i = 1; i <= c1; i++) ans += b1[i].val;
		for (int i = 1; i <= c2; i++) ans += b2[i].val;
		for (int i = 1; i <= c3; i++) ans += b3[i].val;
		printf("%d\n", ans);
	}
	return 0;
}
