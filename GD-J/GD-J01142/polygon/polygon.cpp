#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=1e6+5;
int n,ans,a[maxn],vis[maxn];
void dfs(int x)
{
	if(x>n)
	{
		int mx=0,sum=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(vis[i])mx=max(mx,a[i]),sum+=a[i],cnt++;
		if(sum>2*mx&&cnt>=3)
			ans++;
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
