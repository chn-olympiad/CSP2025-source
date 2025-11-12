#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int Point=1;
int a[5003];
const int MOD=998244353;
struct
{
	int Max,Len,piece;
}dfs[1145140];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		const int PO=Point-1;
		dfs[Point].Max=a[i]*2;
		dfs[Point].Len=a[i];
		dfs[Point].piece=1;
		Point++;
		for(int j=1;j<=PO;j++)
		{
			dfs[Point].Len=dfs[j].Len+a[i];
			dfs[Point].Max=max(a[i]*2,dfs[j].Max);
			dfs[Point].piece=dfs[j].piece+1;
			Point++;
		}
	}
	int ans=0;
	for(int i=1;i<Point;i++)
	{
		if(dfs[i].piece>=3 && dfs[i].Max<dfs[i].Len)
		{
			ans=(ans+1)%MOD;
		}
	}
	printf("%d",ans);
	return 0;
}
