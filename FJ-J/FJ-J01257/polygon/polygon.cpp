#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,g[5050],s[5050],a,maxa=-1e9;
long long ans=0;
bool y[5050];
void dfs(int x,int maxs,int h,int k)
{
	if(x>3&&maxs*2<h)
		ans=(ans+1)%MOD;
	for(int i=k+1;i<=n;i++)
	{
		y[i]=0;
		dfs(x+1,s[i],h+s[i],i);
		y[i]=1;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		g[a]++;
		maxa=max(maxa,a);	
	} 
	a=0;
	for(int i=1;i<=maxa;i++)
		while(g[i])
		{
			s[++a]=i;
			y[a]=1;
			g[i]--;
		}
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}

