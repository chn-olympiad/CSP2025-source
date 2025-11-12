#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],maxn,alln,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i<= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i<= n-2;i++)
	{
		for(int j = i+2; j<= n;j++)
		{
			alln = 0;
			maxn = 0;
			for(int z = i;z <= j;z++)
			{
				alln += a[z];
				if(maxn < a[z])
				{
					maxn = a[z];
				}
			}
			if(2*maxn < alln)
			{
				ans++;
			}
		}
	}
	cout << ans%998244353;
	return 0;
}
