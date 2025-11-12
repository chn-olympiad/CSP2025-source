#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;

typedef long long ll;

const ll N = 510;
ll m, n, a[N], c[N], ans;
bitset<N> vis;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	for (ll i = 1;i <= n;++i) cin >> c[i];
	for (ll i = 1;i <= n;++i) a[i] = i;
	do{
		ll cnt1 = 0, cnt2 = 0;
		for (ll i = 1;i <= n;++i) {
			if (cnt1 >= c[a[i]]) {
				++cnt1;
				continue;
			}
			if (s[i - 1] == '1') ++cnt2;
			else ++cnt1;
		}
		if (cnt2 >= m) ++ans, ans %= MOD;
	}while(next_permutation(a + 1, a + n + 1));
	cout << ans;
	return 0;
}
