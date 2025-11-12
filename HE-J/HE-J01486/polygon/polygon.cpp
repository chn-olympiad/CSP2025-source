#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5100, mod = 998244353;
ll a[N], n, po[N], impo[N], ans;
ll qpow(ll x, ll y)
{
	ll res = 1;
	while(y)
	{
		if(y & 1) res *= x, res %= mod;
		x *= x;x %= mod;y >>= 1;
	}
	return res;
}
ll C(ll m, ll n){return po[n] * impo[m] % mod * impo[n - m] % mod;}
void dfs(ll x, ll su, ll ma, ll step)
{
	if(step >= 3 && ma * 2 < su) ans ++, ans %= mod;
	for(int i = x;i <= n;i ++) dfs(i + 1, su + a[i], max(ma, a[i]), step + 1);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("polygon.in", "r", stdin);freopen("polygon.out", "w", stdout);
	po[0] = 1;
	for(int i = 1;i <= 5000;i ++) po[i] = po[i - 1] * i % mod;
	impo[5000] = qpow(po[5000], mod - 2);
	for(int i = 5000 - 1;i >= 0;i --) impo[i] = impo[i + 1] * (i + 1) % mod;
	cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(n <= 20)
	{
		 dfs(1, 0, 0, 0);
		 cout << ans << '\n';
		 return 0;
	}
	for(int i = 3;i <= n;i ++) ans += C(i, n), ans %= mod;
	cout << ans << '\n';
	return 0;
}
