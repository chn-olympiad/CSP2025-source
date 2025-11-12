#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 5e5 + 10;

using namespace std;

int n, k;
ll a[N];
ll sum[N];
ll f[N][2];
ll ans;
map<ll, ll> mp;


void Debug() {

}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
	}

    for (int i = 1; i <= n; ++i) {
        ll x = sum[i] ^ k;
        if (mp.count(x)) f[i][1] = max(mp[x] + 1, f[i][1]);
        f[i][0] = max(ans, f[i][0]);
        mp[sum[i]] = max({f[i][1], f[i][0]});
        ans = mp[sum[i]];
    }
	cout << ans << '\n';
	return 0;
}
