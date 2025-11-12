#include<cstdio>
int n, m, r, num, t, cnt = 1, lie;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &r);
	t = n * m - 1;
	while (t--) {
		scanf("%d", &num);
		if (num > r) ++cnt;
	}
	lie = (cnt % n) ? cnt / n + 1 : cnt / n;
	printf("%d %d", lie, (lie % 2) ? cnt - (lie - 1) * n : (n + 1) - (cnt - (lie - 1) * n));
	fclose(stdin); fclose(stdout);
	return 0;
}
