#include <bits/stdc++.h>

#define MAX_N (100)

int n, m, a[MAX_N + 1];

main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]);

	int tar = a[1];
	std::sort(a + 1, a + n * m + 1, std::greater<int>());
	for (int i = 1; i <= n * m; i++)
		if (a[i] == tar) { tar = i - 1; break; }

	int c = tar / n + 1;
	int r = (c & 1) ? tar % n + 1 : n - tar % n;

	printf("%d %d\n", c, r);
	return 0;
}
