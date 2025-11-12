#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int a[5100];
int f[5100];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	sort(a + 1,a + n + 1);
	f[0]++;
	f[a[1]]++;
	f[a[2]]++;
	f[min(a[1] + a[2],5001ll)]++;
	int ans = 0;
	for(int i = 3;i <= n;i++)
	{
		for(int j = a[i] + 1;j <= 5001;j++)
		{
			ans += f[j];
			ans %= mod;
		}
		for(int j = 5001;j >= 0;j--)
		{
			if(f[j])
			{
				f[min(5001ll,j + a[i])] += f[j];
				f[min(5001ll,j + a[i])] %= mod;
			}
		}
	}
	cout << ans;
	return 0;
}
