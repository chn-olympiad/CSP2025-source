// 这次好难
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[5100];
ll ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for (ll i = 0; i < (1ll << n); i++) {
		ll cnt = 0, sum = 0, mx = 0;
		for (ll j = 1; j <= n; j++) {
			if (1 & (i >> (j - 1)))
				cnt++, sum += a[j], mx = max(mx, a[j]);
		}
		if (cnt >= 3 && sum > mx * 2)
			ans++, ans %= 998244353;
	}
	
	/*sort(a + 1, a + n + 1, [&](const ll &a, const ll &b) {
		return a < b;
	});
	for (ll i = 1; i <= n; i++) {
		sum += a[i];
		if (i >= 3) {
			// count
			ll k = sum - a[i] * 2;
			if (k == 0)
				continue;
			ll l = 0, r = n + 1;
			while (l + 1 < r) {
				ll mid = (l + r) / 2;
				if (a[mid] <= k)
					l = mid;
				else
					r = mid;
			}
			ans += l; // del 1
			for ()
		}
	}*/
	printf("%lld\n", ans % 998244353);
}
/*
种花
***** ***** ***** ***** ***** ***** ***** ***** ****  * ***** ***** * ***** *   * *     ***** *
*     *     *       *   *   	*   *   * *   * *   * * *     *     * *     *   * *       *   *
*     *     ****    *   *****   *   *   * *   * *   * * ****  ****  * *     *   * *       *   *
*     *     *       *       *	*   *   * *   * *   * * *     *     * *     *   * *       *   
***** ***** *     ***** *****	*   ***** ***** ****  * *     *     * ***** ***** *****   *   *
*/