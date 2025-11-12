#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[50000000],dp[5005],ans=0,t=0;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum[++t]=a[1]+a[2];
	for(int i=3;i<=n;i++)
	{
		int m=t;
		for(int j=1;j<=m;j++)
		{
			sum[++t]=a[i]+sum[j];
			if(a[i]<sum[j])ans++;	
		}
		for(int j=1;j<i;j++)sum[++t]=a[i]+a[j];
	}
	cout<<ans;
	return 0;
}