#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=20)
	{
		int cnt = 0,mx = 0,ans = 0,x;
		for(int i = 0;i<(1<<n);i++)
		{
			cnt = 0,mx = 0,x = 0;
			for(int j = 0;j<n;j++)
			{
				if(i&(1<<j))
				{
					cnt+=a[j+1];
					mx = max(mx,a[j+1]);
					x++;
				}
			}
			if(cnt>2*mx&&x>=3)
			{
				ans++;
			}
			ans = ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	long long x = 1;
	for(int i = 1;i<=n;i++)
	{
		x = x*2%998244353;
	}
	cout<<x-n-n*(n-1)/2;
	return 0;
}
