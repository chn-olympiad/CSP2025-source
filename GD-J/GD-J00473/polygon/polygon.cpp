#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,qi[5005],mod=998244353;
void dfs(long long len,long long d,long long zh,long long maxx,long long gs)
{
	if(gs==len)
	{
		if(zh>2*maxx)ans=(ans+1)%mod;
		return ;
	}
	for(int i=d+1;i<=n;i++)
	{
		long long zz=zh+a[i],maxy=max(maxx,a[i]);
		dfs(len,i,zz,maxy,gs+1);		
	}

	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int l=3;l<=n;l++)
		for(int i=1;i<=n-l+1;i++)
			dfs(l,i,a[i],a[i],1);
	printf("%lld",ans);
	return 0;
} 
