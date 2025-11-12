#include<bits/stdc++.h>
using namespace std;
int f[5005],a[5005],ans,pows = 1;
const int mod = 998244353; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		ans = 1ll * (pows + ans) % mod;
		for(int j = 0; j <= a[i]; j++)
		{
			ans = 1ll * (ans - f[j] + mod) % mod;
		}
		for(int j = a[n]; j >= a[i]; j--)
		{
			f[j] = 1ll * (f[j - a[i]] + f[j]) % mod;
		}
		pows = pows * 2 % mod;
	}
	cout << ans;
	return 0;
}
