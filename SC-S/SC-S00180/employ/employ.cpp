/*
8+20
*/
#include<bits/stdc++.h>
using namespace std;
const int N=510;
const long long MOD=998244353;
int n,m,c[N];
char s[N];
bool flag[N];
int ans,res[N];
long long jc[N];
void check()
{
	int ct=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			ct++;
			continue;
		}
		if(ct>=c[res[i]]) ct++;
		else cnt++;
	}
	ans+=(cnt>=m);
}
void dfs(int x)
{
	if(x==n+1)
	{
		check();
		return;
	}
	for(int i=1;i<=n;i++)
		if(!flag[i])
			res[x]=i,flag[i]=1,dfs(x+1),flag[i]=0;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<=20)
		dfs(1),printf("%d\n",ans);
	else
	{
		jc[0]=1;
		for(int i=1;i<=n+10;i++)
			jc[i]=jc[i-1]*i%MOD;
		printf("%lld\n",jc[n]);
	}
	return 0;
}