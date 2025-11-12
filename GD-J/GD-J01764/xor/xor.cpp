#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct zb
{
	int l,r;
}senn[500003];
int Point=1;
int n,k;
int dp[500003];
int a[500003];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int Num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				Num=a[i];
			}else
			{
				Num=(Num xor a[j]);
			}
			if(Num==k)
			{
				senn[Point].l=i;
				senn[Point].r=j;
				Point++;
			}
		}
	}
	dp[1]=1;
	int Max=1;
	for(int i=1;i<Point;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(senn[j].r<senn[i].l)
			{
				dp[i]=max(1+dp[j],dp[i]);
				if(dp[i]>Max) Max=dp[i];
			}
		}
	}
	printf("%d",Max);
	return 0;
}
