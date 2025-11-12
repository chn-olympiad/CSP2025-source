#include <bits/stdc++.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define chkmax(u, v) ((u) = max(u, v))

#define MAX_N ((int) 5e5)
#define MAX_V (1 << 20)

int n, k, a[MAX_N + 1];

#define OO (0x3f3f3f3f)

int f[MAX_N + 1], g[MAX_V];

main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];

	for (int i = 1; i < MAX_V; i++) g[i] = -OO;
	for (int i = 1; i <= n; i++) {
		f[i] = max(f[i - 1], g[a[i] ^ k] + 1);
		chkmax(g[a[i]], f[i]);
	}
	
	printf("%d\n", f[n]);
	return 0;
}
