#include<bits/stdc++.h>
using namespace std;
long long const mod=998244353;
long long n,a[5200],ans;
void dfs(long long k,long long sum,long long maxx)
{
	if(k>n)
	{      
		if(sum>2*maxx)
		{
			ans++;
			ans=(ans+mod)%mod;
		}
		return;
	}
	dfs(k+1,sum+a[k],max(maxx,a[k]));
	dfs(k+1,sum,maxx);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);	
	} 
	sort(a+1,a+1+n);
	dfs(1,0,0);
	ans=(ans+mod)%mod;
	printf("%lld",ans);
	return 0;
}
