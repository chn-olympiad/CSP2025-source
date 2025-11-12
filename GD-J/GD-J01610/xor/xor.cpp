#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],dp[1000005];
int cnt=0;
struct u
{
	int l,r;
}c[1000005];
void push(int l1,int r1)
{
	cnt++;
	c[cnt].l=l1;
	c[cnt].r=r1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int xr=a[i];
		for(int j=i;j<=n;j++)
		{
			if(((xr^a[j])==k&&i!=j)||(i==j&&xr==k))
			{
				push(i,j);
			}
			if(i!=j)xr^=a[j];
		}
	}
	if(cnt==0)
	{
		printf("%d",0);
		return 0;
	}
	int maxn=1;
	dp[1]=1;
	for(int i=2;i<=cnt;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(c[i].l>c[j].r)
			{
				dp[i]=max(dp[i],dp[j]+1);
				maxn=max(maxn,dp[i]);
			}
		}
	}
	printf("%d",maxn);
	return 0;
}
