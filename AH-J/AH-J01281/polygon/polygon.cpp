#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],maxn;
long long mod=998244353,ans;
void dfs(int idx,int sum,int maxn,int cnt)
{
	if(idx==n+1)
	{
		if(sum>2*maxn&&cnt>=3)
			ans=(ans+1)%mod;
		return ;
	}
	dfs(idx+1,sum,maxn,cnt);
	dfs(idx+1,sum+a[idx],max(maxn,a[idx]),cnt+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(maxn==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*2%mod;
		ans=(ans-n-1)%mod;
		ans=(ans-n*(n-1)/2)%mod;
		printf("%lld",ans%mod);
		return 0;
	}
	if(n<=20)
	{
		dfs(1,0,0,0);
		printf("%lld",ans%mod);
	}
	return 0;
}
