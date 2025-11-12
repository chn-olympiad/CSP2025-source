#include <bits/stdc++.h>
int num[500005], ji[500005], tong[1 << 21];
int main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", num + i), ji[i] = ji[i - 1] ^ num[i];
	int ans = 1;
	tong[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (tong[ji[i] ^ k] == ans) ++ans;
		tong[ji[i]] = ans;
	}
	printf("%d", ans - 1);
}
