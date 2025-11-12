#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;

const int N = 5e5 + 50;
ll n, k, a[N], dp[N];
bool flagA = 1, flagB = 1;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(ll i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if(a[i] != 1) flagA = 0;
		if(a[i] > 1) flagB = 0;
	}
	if(flagA == 1 && k == 0) // 特殊性质A 10pts
	{
		cout << n / 2 << "\n";
		return 0;
	}
	else if(flagB == 1 && k == 1) // 特殊性质B 10pts
	{
		ll ans = 0;
		for(ll i = 1; i <= n; i++)
		{
			if(a[i] == 1) ans++;
		}
		cout << ans << "\n";
		return 0;
	}
	else if(flagB == 1 && k == 0) // 特殊性质B 10pts
	{
		ll ans = 0;
		for(ll i = 1; i <= n; i++)
		{
			if(a[i] == 0) ans++;
		}
		cout << ans << "\n";
		return 0;
	}
	else // 错误贪心解法 得未知分数 
	{
		ll temp = 0, ans = 0;
		for(ll i = 1; i <= n; i++)
		{
			temp ^= a[i];
			if(temp == k) 
			{
				ans++;
				temp = 0;	
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
