#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],vis[5];
long long ans;
void dfs(int x,long long sum)
{
	if(x>n)
	{
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(vis[i]<(n/2))
		{
			vis[i]++;
			dfs(x+1,sum+a[x][i]);
			vis[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		dfs(1,0);
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
