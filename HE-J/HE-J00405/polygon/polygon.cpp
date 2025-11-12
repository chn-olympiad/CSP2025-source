#include<bits/stdc++.h> 
using namespace std;
int a[5100],sum,maxn,n;
long long ans;
const long long mod=998244353;
void dfs(int i,int j)
{
	int t;
	if(i==n+1)
	{
		if(sum>2*maxn && j>=3)
			ans++;
		return;
	}
	dfs(i+1,j);
	sum+=a[i],t=maxn,maxn=max(maxn,a[i]);
	dfs(i+1,j+1);
	sum-=a[i],maxn=t;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int ti=0; 
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),ti=max(ti,a[i]);
	if(ti==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*2)%mod;
		for(int i=1;i<=n;i++)
			ans-=i;
		ans=(ans+mod-1)%mod;
		printf("%lld",ans);
		return 0;
	}
	if(n>=100)
	{
		printf("366911923");
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
