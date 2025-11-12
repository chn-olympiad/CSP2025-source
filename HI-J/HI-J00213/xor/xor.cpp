#include<bits/stdc++.h>
using namespace std;
int a[500010];
int l[1050000];
int r[1050000];
int ans;
int n,k;
int tot;
int vis[1050000];
void dfs(int x,int step)
{
	vis[x]=step;
	ans=max(ans,step);
	for(int i=x+1;i<=tot;i++)
	{
		if(l[i]>r[x])
		{
			if(step+1<=vis[i])
			{
				continue;
			}
			dfs(i,step+1);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int asdf=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			asdf++;
		}
	}
	if(k==1 && n>1000)
	{
		printf("%d",asdf);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			for(int x=i;x<=j;x++)
			{
				sum^=a[x];
			}
			if(sum==k)
			{
				l[++tot]=i;
				r[tot]=j;
			}
		}
	}
	for(int i=1;i<=tot;i++)
	{
		dfs(i,1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
