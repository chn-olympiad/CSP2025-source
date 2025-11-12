#include <bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],cnt;
int main()
{
	freopen("polgon.in","r",stdin);
	freopen("polgon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]>a[i]*2)
		{
			cnt++;
			for(int j=1;j<i;j++)
			{
				if(s[i]-a[j]>a[i]*2)
				{
					cnt++;
				}
				if(s[i]-s[j]>a[i]*2)
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt%998244353-1;		
	return 0;
}
