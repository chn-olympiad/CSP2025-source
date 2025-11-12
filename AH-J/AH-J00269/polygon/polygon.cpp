#include <bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005],maxx=-1,sum=0,ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3])) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		maxx=a[i];
		sum=0;
		for(int j=i+2;j<=n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				maxx=max(maxx,a[i]);
				sum+=a[i];
			}
			if(sum>maxx*2) ans++;
		}
	}
	cout<<ans;
	return 0;
}
