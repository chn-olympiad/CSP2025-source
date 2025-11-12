#include <iostream>
#include <cstdio>
#define ll unsigned long long
using namespace std;
ll n, a[5005], smr[5005], mod = 998244353, nsm, ans, now_sum, now[5005];
ll smul(ll x) {
	if (smr[x]) return smr[x];
	ll res = 1;
	for (ll i = 2; i <= x; i++) {
		res *= i; res %= mod;
	}
	return smr[x] = res;
}
void dfs(ll num, ll maxn, ll add, ll pos) {
	maxn = max(maxn, add); now_sum += add;
	if (num > 2 && now_sum > 2 * maxn) ans = (ans + 1) % mod;
	for (int i = pos; i <= n; i++) {
		if (!now[i]) {
			now[i] = 1;
			dfs(num+1, maxn, a[i], i);
			now[i] = 0;
		}
	}
	now_sum -= add;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%llu", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%llu", &a[i]);
	}
	if (n <= 3) {
		if (n < 3) printf("0");
		else {
			ll sum = 0, maxn = 0;
			for (int i = 1; i <= n; i++) {
				maxn = max(maxn, a[i]);
				sum += a[i];
			}
			if (sum > maxn * 2) printf("1");
			else printf("0");
		}
	}
	else if (n <= 20) {
		for (int i = 1; i <= n; i++) {
			now[i] = 1;
			dfs(1, 0, a[i], i);
			now[i] = 0;
		}
		printf("%llu", ans);
	}
	else {
		nsm = smul(n);
		for (int i = 3; i <= n; i++) {
			ans += nsm / (smul(i) * smul(n - i) % mod);
			ans %= mod;
		}
		printf("%llu", ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
