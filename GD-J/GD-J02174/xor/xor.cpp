// 这次好难
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, a[500100], ans, dp[1100][1100];
pair<int, int> b[500100];
vector<pair<ll, ll>> lne;

bool check(ll l, ll r) {
	for (ll i = l; i <= r; i++)
		if (b[i] != make_pair(0, 0)) {
			// printf("%d-%d : ", b[i].first, b[i].second);
			return false;
		}
	return true;
}

void fill(ll l, ll r) {
	for (ll i = l; i <= r; i++)
		b[i] = {l, r};
}
// 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (ll i = 1; i <= n; i++)
		for(ll j = 1; j <= i; j++) {
			dp[j][i] = dp[j][i - 1] ^ a[i];
			if (dp[j][i] == k)
				lne.push_back({j, i});
		}
	sort(lne.begin(), lne.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> &b) {
		return a.second - a.first < b.second - b.first || (a.second - a.first == b.second - b.first && a.first < b.first);
	});
	for (auto i : lne) {
		if (check(i.first, i.second)) {
		// printf("%d(%d) %d(%d)\n", i.first, a[i.first], i.second, a[i.second]);
			ans++, fill(i.first, i.second);
		} else {
		// printf("%d(%d) %d(%d)\n", i.first, a[i.first], i.second, a[i.second]);

		}
	}
	// for (int i = 1; i <= n; i++)
	// 	printf("%d %d\n", a[i], b[i]);
	printf("%lld\n", ans);
}
/*
种花
***** ***** ***** ***** ***** ***** ***** ***** ****  ***** ***** ***** ***** ***** *   * *     ***** *
*     *     *       *   *   	*   *   * *   * *   *   *   *     *       *   *     *   * *       *   *
*     *     ****    *   *****   *   *   * *   * *   *   *   ****  ****    *   *     *   * *       *   *
*     *     *       *       *	*   *   * *   * *   *   *   *     *       *   *     *   * *       *   
***** ***** *     ***** *****	*   ***** ***** ****  ***** *     *     ***** ***** ***** *****   *   *
*   * ***** *   * *   * *   * ***** ***** *   * ***** ***** ***** ***** *
 * *  *   * *   * *   * *   * *   * *     **  * *   * *     *   * *   * *
  *   *   * *   * ***** *   * ***** ***** * * * *   * ***** ***** ***** *
  *   *   * *   * *   *  * *  *   * *     *  ** *   * *     	*     * 
  *   ***** ***** *   *   *   *   * ***** *   * ***** ***** ***** ***** *
*/