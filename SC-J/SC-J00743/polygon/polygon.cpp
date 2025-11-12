#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
/*
int fastpow(int a, int b, int p)
{
	int res = 1;
	while(b != 0)
	{
		if(b % 2 == 1) res = res * a % p;
		a = a * a % p;
		b /= 2;
	}
	return res;
}
*/
ll jiecheng(ll n)
{
	ll res = 1;
	for(ll i = 1; i <= n; i++)
	{
		res *= i;
		res %= MOD;
	}
	return res;
}
ll jiecn = 1;
ll cmn(ll m, ll n)
{
	ll res = 1;
	res = (jiecn / (jiecheng(m) * jiecheng(n - m))) % MOD;
	return res;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n;
	cin >> n;
	vector<ll> a(n + 10);
	ll amax = 0;
	for(ll i = 0; i < n; i++)
	{
		cin >> a[i];
		amax = max(amax, a[i]);
	}
	
	if(n <= 3)
	{
		ll max1 = 0;
		ll cnt = 0;
		for(ll i = 0; i < n; i++)
		{
			max1 = max(a[i], max1);
			cnt += a[i]; 
		}
		if(cnt > max1 * 2)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	else if(amax == 1)
	{
		ll ans = 0;
		for(ll i = 1; i <= n; i++)
		{
			jiecn *= i; 
		} 
		for(ll i = 3; i <= n; i++)
		{
			ans += cmn(i, n);
		}
		cout << ans;
		return 0;
	}
	return 0;
}