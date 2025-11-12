#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],maxx,ans,C[5005][5005],mod=998244353;
void dfs(int k,int maxx,int sum)
{
	if(k>n)
	{
		if(sum>maxx*2) ans=(ans+1)%mod;
		return;
	}
	dfs(k+1,maxx,sum);
	dfs(k+1,max(maxx,a[k]),sum+a[k]);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(n<=20)
	{
		dfs(1,0,0);
		printf("%lld",ans);
		return 0;
	}
	if(maxx!=1) return 0;
	C[0][0]=1;
	for(int i=1;i<=n;i++) for(int j=0;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=3;i<=n;i++) ans=(ans+C[n][i])%mod;
	printf("%lld",ans);
	return 0;
}
