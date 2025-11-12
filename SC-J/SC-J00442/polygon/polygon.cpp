#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,mx;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		mx=max(a[i],mx);
	}
	if(n==3)
	{
		if(mx*2<sum) printf("1");
		else printf("0");
	}
	else if(mx==1)
	{
		long long ans=0;
		for(int i=3;i<=n;i++)
		{
			long long ji=1,flag[5005];
			for(int j=2;j<i;j++)
			{
				flag[j]=1;
			}
			for(int j=n;j>=i+1;j--)
			{
				ji=(ji*j)%998244353;
				for(int k=2;k<i;k++)
				{
					if(!flag[k]) continue;
					if(ji%k==0)
					{
						flag[k]=0;
						ji=ji/k;
					}
				}
			}
			ans=(ans+ji)%998244353;
		}
		printf("%lld",ans);
	}
	else printf("0");
	return 0;
}