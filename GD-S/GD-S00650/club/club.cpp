#include <stdio.h>
#include <stdlib.h>
#ifdef FKZLOVESDEBUG
#undef FKZLOVESDEBUG
#endif
int max(const int a, const int b) {
	return a > b ? a : b;
}
int max3(const int a, const int b, const int c) {
	return max(a, max(b, c));
}
int T, n, n1, a1[100001], a2[100001], a3[100001], len1, len2, len3, cha[100001], a[100001][4], mx, cm, tot;
int cmp(const void *a, const void *b) {
	return cha[*(int *) a] > cha[*(int *) b] ? 1 : -1;
}
int main() {
	#ifndef FKZLOVESDEBUG
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		n1 = n >> 1;
		tot = len1 = len2 = len3 = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			mx = max3(a[i][1], a[i][2], a[i][3]);
			if (mx == a[i][1]) {
				a1[len1++] = i;
				cm = max(a[i][2], a[i][3]);
			}
			else if (mx == a[i][2]) {
				a2[len2++] = i;
				cm = max(a[i][1], a[i][3]);
			}
			else {
				a3[len3++] = i;
				cm = max(a[i][1], a[i][2]);
			}
			cha[i] = mx - cm;
			tot += mx;
		}
		if (len1 > n1) {
			qsort(a1, len1, sizeof(int), cmp);
			for (int i = 0; i < len1 - n1; ++i) {
				tot -= cha[a1[i]];
			}
		}
		else if (len2 > n1) {
			qsort(a2, len2, sizeof(int), cmp);
			for (int i = 0; i < len2 - n1; ++i) {
				tot -= cha[a2[i]];
			}
		}
		else if (len3 > n1) {
			qsort(a3, len3, sizeof(int), cmp);
			for (int i = 0; i < len3 - n1; ++i) {
				tot -= cha[a3[i]];
			}
		}
		printf("%d\n", tot);
	}
}
