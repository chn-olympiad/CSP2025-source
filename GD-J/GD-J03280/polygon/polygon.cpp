#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int n, a[5005], maxn = -1;
ll b[5010], ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), maxn = max(maxn, a[i]);
	sort(a + 1, a + n + 1);
	maxn++;
	for (int i = 1; i <= n; i++) {
		ll res = b[maxn];
		b[maxn] *= 2;
		b[maxn] %= mod;
		for (int j = maxn - 1; j > 0; j--) {
			if (j > a[i]) {
				res += b[j];
				res %= mod;
			}
			b[min(j + a[i], maxn)] += b[j];
			b[min(j + a[i], maxn)] %= mod;
		}
		b[a[i]]++;
		b[a[i]] %= mod;
		ans += res;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
