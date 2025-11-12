#include <bits/stdc++.h>
using namespace std;
const long long N = 5010;
const long long P = 998244353;
long long n;
long long a[N], sum[N];
long long f[510][50010];
long long quickpow(long long n) {
	long long ans = 1, a = 2;
	for (; n; n >>= 1) {
		if (n & 1) ans = (ans * a) % P;
		a = (a * a) % P;
	}
	return ans;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	bool fla = true;
	for (long long i = 1; i <= n; i++)
		scanf("%lld", &a[i]), fla &= (a[i] == 1ll);
	if (fla) {
		long long ans = (quickpow(n) - n + P) % P;
		ans -= n * (n - 1ll) / 2ll;
		ans--;
		ans %= P;
		ans += P;
		ans %= P;
		printf("%lld", ans);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (long long i = 1; i <= n; i++) 
		f[i][a[i]] = 1;
	for (long long i = 1; i <= n; i++) 
		for (long long j = 1; j <= sum[i]; j++) 
			for (long long k = 1; k < i; k++)
				f[i][j] += f[k][max(j - a[i], 0ll)], f[i][j] %= P;
	long long ans = 0ll;
	for (long long i = 1; i <= n; i++) {
		long long maxn = a[i] * 2ll + 1ll;
		long long cnt = 0ll;
		for (long long j = maxn; j <= sum[i]; j++) 
			cnt += f[i][j], cnt %= P;
		cnt %= P;
		ans += cnt;
		ans %= P;
	} 
	printf("%lld", ans);
	return 0;
} 
