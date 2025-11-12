#include<bits/stdc++.h>
using namespace std;
long long i,j,c=0,n,a[10000],ma=-1,ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	long long f=pow(2,n)-1;
	for(i=7;i<=f;i++)
	{
		for(j=0;j<n;j++)
		{
			long long f2=pow(2,j);
			if((i&f2)!=0)
			{
				c+=a[j];
				ma=max(ma,a[j]);
			}
		}
		if(c>ma*2)ans++;
		ma=-1;
		c=0;
	}
	printf("%lld",ans%998244353);
	return 0;
} 