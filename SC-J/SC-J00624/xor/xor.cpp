#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , k;
ll a[500005] , f[500005];
ll need[500005];
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		f[i] = f[i - 1]^ a[i];
		need[i] = f[i]^ k;
	}
	int lst = 0 , ans = 0;
	for(int i = 1;i <= n;i++)
	{
		ll x = lower_bound(f + lst , f + i , need[i]) - f;
		if(f[x]!= need[i])
		{
			continue;
		}
		ans++;
		lst = i;
	}
	cout << ans;
	return 0;
}