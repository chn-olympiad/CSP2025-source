#include<bits/stdc++.h>
using namespace std;
const int modd=998244353;
int n,a[5010],pd,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]==1)
			pd++;
	}
	if(n==3)
	{
		sort(a+1,a+n+1);
		if((a[1]+a[2]+a[3])>(a[3]*2))
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(pd==n)
	{
		for(int i=3;i<=n;i++)
		{
			int z=1;
			for(int j=n;j>=1;j--)
			{
				z*=j;
				z%=modd;
			}
			int m=1;
			for(int j=i;j>=1;j--)
			{
				m*=j;
				m%=modd;
			}
			ans=ans+z/m;
			ans%=modd;
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
