#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,ans=0,r=0;
void dfs(long long q,long long w,long long e,long long r)
{
	if(q==n)
	{
		if(r>=3&&w>e*2)
			ans++;
		ans=ans%998244353;
		return;
	}
	dfs(q+1,w,e,r);
	dfs(q+1,w+a[q],max(e,a[q]),r+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=0;i<n;i++)
		scanf("%lld",&a[i]);
	dfs(0,0,0,0);
	ans=ans%998244353;
	printf("%lld",ans);
	return 0;
}
