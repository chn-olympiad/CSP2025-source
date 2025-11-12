#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353, N = 5010;
int a[N], jc[N], pjc[N], s[N];
int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)ans = 1ll * ans * a % mod;
		a = 1ll * a*a % mod;
		b >>= 1;
	}
	return ans;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	if (n == 3) printf("%d", s[2] > a[3]);
	else {
		int ans = 0;
		jc[0] = 1;
		for (int i = 1; i <= n; i++)jc[i] = 1ll * jc[i - 1] * i % mod;
		pjc[n] = qpow(jc[n], mod - 2);
		for (int i = n; i > 0; i--)pjc[i - 1] = 1ll * pjc[i] * i % mod;
		for (int i = 3; i <= n; i++)
			ans = (ans + 1ll * jc[n] * pjc[i] % mod * pjc[n - i] % mod) % mod;
		printf("%d", ans);
	}
}