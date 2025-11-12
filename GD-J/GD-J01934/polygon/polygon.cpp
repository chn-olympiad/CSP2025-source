#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans,vis[5005];
void dfs(int tmp,int x,int sum,int maxx,int cnt)
{
	if(x>tmp)
	{
		if(sum>maxx*2) ans=(ans+1)%mod;
		return ;
	} 
	for(int i=cnt+1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(tmp,x+1,sum+a[i],max(maxx,a[i]),i);
			vis[i]=0;
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
		memset(vis,0,sizeof vis);
		dfs(i,1,0,0,0);
	}
	ans=ans%mod;
	printf("%d",ans);
	return 0;
}

