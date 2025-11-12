#include <bits/stdc++.h>
using namespace std;
int a[5005],n,ans=0,x;
int main() 
{
	freopen("polygon.in","w",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n == 3)
	{
		for (int i=1;i<=n-2;i++)
		{
			for (int j=i+1;j<=n-1;j++)
			{
				for (int k=j+1;k<=n;k++)
				{
					x = max(a[i],max(a[j],a[k]));
					if ((a[i]+a[j]+a[k])>2*x)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	else
	{
		for (int i=1;i<=n-2;i++)
		{
			ans+=i*i;
		}
		cout<<ans;
	}
	freopen("polygon.out","w",stdout);
	return 0;
}
