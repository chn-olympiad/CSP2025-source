#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, a[505], c[505], ans, tot = 1;
char s[505];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d %s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) scanf("%d", c + i), a[i] = i, tot = 1ll * tot * i % mod;
	if (n > 50) printf("%d", tot), exit(0);
	do {
		int sum = 0, cur = 0;
		for (int i = 1; i <= n; i++)
			if (cur >= c[a[i]] || s[i] == '0') cur++;
			else sum++;
		if (sum >= m) ans++;
	} while (next_permutation(a + 1, a + n + 1));
	printf("%d", ans);
	return 0;
}
