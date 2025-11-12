#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define V vector
using namespace std;

const ll maxn = 5e3;
const ll maxa = 5e3;
const ll mod = 998244353;

ll n;
ll a[maxn + 5];

ll qpow(ll a, ll b)
{
	if(!b) return 1;
	ll tmp = qpow(a, b>>1);
	return tmp * tmp % mod * (b&1 ? a : 1ll) % mod;
}

ll dp[maxn + 5][maxa + 5][3];
ll dfs(ll i, ll j, ll k)
{
	ll& f = dp[i][j][k];
	if(~f) return f;
	if(i == 0) return f = (k == 2 && j == 0);
	f = dfs(i-1, j, k);
	if(j >= a[i]) f += dfs(i-1, j-a[i], k<2 ? k+1 : 2);
	return f %= mod;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, 0xff, sizeof dp);
	cin >> n;
	for(ll i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+n+1);
	ll ans = 0;
	for(ll i = 3; i <= n; ++i)
	{
		ll sum = 0;
		for(ll j = 0; j <= a[i]; ++j)
			sum += dfs(i-1, j, 0),
			sum %= mod;
		ll d = qpow(2, i-1) - sum - i;
		ans += (d + mod*3) % mod;
		ans %= mod;
	}
	cout << ans << '\n';

	return 0;
}
/*
9:25
expected pts: 400
10:00
肚子疼，刚去了趟WC，稀里哗啦的，结果还是疼
拉的时候发现T1好像有点问题(只有多个0)
哦，没问题了， 不可能只有0。 
*/