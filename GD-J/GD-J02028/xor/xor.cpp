#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll n, k, a[N], dp[N], mx[N];
//dp[i]前i位的方案数 
//mx[i]前i位最大的dp[j]
map<ll, ll> mp;
//mp[i]上一个前缀异或和为i的所有位置
int main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i - 1];
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		ll x = a[i] ^ k;
		if (mp.count(x)) {
			ll last = mp[x];
			dp[i] = mx[last] + 1;
		}
		mx[i] = max(mx[i - 1], dp[i]);
		mp[a[i]] = i;
	}
	cout << mx[n];
	return 0;
}
