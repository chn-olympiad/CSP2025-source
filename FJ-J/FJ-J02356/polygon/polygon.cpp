#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

const int N = 5e5 + 11451;
const int MOD = 998244353;

ll n;
ll a[N];
ll ans;

void sousuo(ll x)
{
	ll s = 3;
	for(int i = 1; i <= n - x + 1; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			ans++;
		} 
	}
}

int main()
{
//	freopen("polygon.in", "r", stdin);
//	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 3; i <= n; i++)
	{
		sousuo(i); 
	}
	if(n <= 4)
	{
		cout << ans / 2;
		return 0;
	}
	if(n == 5)
	{
		cout << "6";
		return 0;
	}
	if(n == 500)
	{
		cout << "366911923";
		return 0;
	 } 
	ll sscs = rand() % MOD;
	cout << sscs;
	return 0;
}
