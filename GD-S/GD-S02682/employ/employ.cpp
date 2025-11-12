#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,die,c[510],cho[510],ans,might=1;
char s[510];
bool vis[510];
void dfs(long long num,long long now)
{
	if(num==n+1)
	{
		if(now>=m)
		{
			ans+=might;
			ans%=mod;
		}
		return;
	}
	if(s[num]=='0')
	{
		dfs(num+1,now);
		return;
	}
	for(long long i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if((num-1-now)>=c[i])
		{
			dfs(num+1,now);
		}
		else
		{
			dfs(num+1,now+1);
		}
		vis[i]=0;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(long long i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			die++;
			might*=die;
			might%=mod;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	dfs(1,0);
	printf("%lld",ans);
}
