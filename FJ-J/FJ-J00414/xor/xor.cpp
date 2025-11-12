#include <bits/stdc++.h>
const int N = 2e6 + 5;

int n, k, a[N], ans;
int buc[N];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i), a[i] ^= a[i - 1];
	int p = 0; ++buc[0];
	for (int i = 1; i <= n; ++i) {
		if (buc[a[i] ^ k]) {
			++ans;
			while (p < i) --buc[a[p++]];
		} ++buc[a[i]];
	} printf("%d", ans);
	return 0;
}
