#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[500000+10],qzh[500000+10],n,k,ans=0;
int vis[500000+10],amax[500000+10];
int dfs(int lae,int cho)
{
	ans=max(ans,cho);
	if(vis[lae])
	{
		vis[lae]=max(vis[lae],cho);
		ans=max(ans,vis[lae]+amax[lae]+1);
		return amax[lae]+1;
	}
	if(lae==n+1)
	{
		return 0;
	}
	for(int i=lae-1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if((qzh[i]^qzh[j])==k)
			{
				vis[j]=max(vis[j],cho);
				amax[lae]=max(dfs(j+1,cho+1),amax[lae]);
			}
	return amax[lae]+1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		qzh[i]=qzh[i-1]^s[i];
	}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
