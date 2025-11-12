#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define il inline
using namespace std;

const int MOD=998244353;
const int MAXN=5e2+7;

int n,m,c[MAXN],bz[MAXN],ans;
char s[MAXN];

void dfs(int t,int sum)
{
	if(t>n)
	{
		if(sum>=m)
			ans=(ans+1)%MOD;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(bz[i])
			continue ;
		bz[i]=1;
		dfs(t+1,sum+((s[t]=='1') and c[i]>sum));
		bz[i]=0;
	}
}

int main()
{
	fre("employ");
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	int one=0;
	for(int i=1;i<=n;i++)
		one+=(s[i]=='1');
	if(one==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
			ans=1ll*ans*i%MOD;
		printf("%d",ans);
		return 0;
	}
	if(one<m)
	{
		puts("0");
		return 0;
	}
	if(n<=10)
	{
		dfs(1,0);
		printf("%d",ans);
	}
	return 0;
}
