#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;

const int N = 5050;
const int Mod = 998244353;
ll n, max_ai = 0, ans = 0, a[N];
vector<ll> temp;

void dfs(ll dep, ll sum, ll maxn)
{
	if(dep > n)
	{
//		cout << "sum = " << sum << "		maxn = " << maxn << "\n";
		if(sum > 2 * maxn) ans = (ans + 1) % Mod;
		return;
	}
	dfs(dep + 1, sum + a[dep], max(maxn, a[dep]));	
	dfs(dep + 1, sum, maxn);
}

ll C(ll n, ll x)
{
	ll res = 1; 
	for(ll i = n; i >= n - x + 1; i--) res = res * i % Mod;
	for(ll i = x; i >= 1; i--) res = res / i;
	return res % Mod;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(ll i = 1; i <= n; i++) 
	{
		cin >> a[i];
		max_ai = max(max_ai, a[i]);
	}
	if(n <= 20) // 40pts
	{
		dfs(1, 0, 0);
		cout << ans % Mod << "\n";
		return 0;
	}
	else if(max_ai == 1) // 24pts
	{ 
		for(ll i = 3; i <= n; i++) ans = (ans + C(n, i)) % Mod;
		cout << ans % Mod << "\n";
		return 0;
	}
	return 0;	
}
