#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for (int i=n;i>=3;i--)
	{
		sum-=a[i+1];
		if (sum<=a[i]*2)
			continue;
		else{
			ans++;
			for (int j=1;j<=i-1;j++)
			{
				int x=sum-a[j];
				if (x>a[i]*2)
				{
					ans++;
				}
				for (int k=2;k<=i-1;k++)
				{
					if (a[j]==a[k])
						continue;
					int y=x-a[k];
					if (y>a[i]*2)
					{
						ans++;
					}
				}
			}
		}
	}
	cout<<ans%998244353;
}

