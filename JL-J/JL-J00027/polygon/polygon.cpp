#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int n,a[5050],num[5050],cnt,res;
void dfs(int x,int y)
{
	for(int i=y;i<=n;i++)
	{
		num[++cnt]=a[i];
		if(cnt<x)
		{
			dfs(x,i+1);
			cnt--;
		}
		else if(cnt==x)
		{
			int sum=0,maxx=0;
			for(int j=1;j<=cnt;j++)
			{
				sum+=num[j];
				maxx=max(maxx,num[j]);
			}
			if(sum>maxx*2)
			{
				res++;
				res%=mod;
			}
			cnt--;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=3;i<=n;i++)
	{
		dfs(i,1);
	}
	printf("%d",res);
	return 0;
}
