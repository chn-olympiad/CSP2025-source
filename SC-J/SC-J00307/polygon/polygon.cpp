#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int N = 5000 + 5;

ll n;
ll a[N];
ll ans;

vector<ll> vec;

void dfs(int k, int cnt) {
	if (k == n + 1) {
		if (cnt < 3) return;
		else {
			ll tot = 0, max_l = 0;
			for (auto x : vec) {
				tot += a[x];
				max_l = max(max_l, a[x]);
			}

			if (tot > max_l * 2) {
				ans ++;
				ans %= MOD;
			}

			return;
		}
	}

	vec.push_back(k);
	dfs(k + 1, cnt + 1);
	vec.pop_back();

	dfs(k + 1, cnt);
}

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	dfs(1, 0);

	cout << ans % MOD << '\n';

	return 0;
}