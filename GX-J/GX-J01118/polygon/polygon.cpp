#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,a[505],vis[505];
void dfs(int st,int k,int s)
{
	if(st>n)
	{
		if(k>=3&&s>vis[k]*2)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	dfs(st+1,k,s);
	vis[k+1]=a[st];
	dfs(st+1,k+1,s+a[st]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n>20)
	{
		for(int i=3;i<=n;i++)
		{
			long long sum=1;
			for(int j=n;j>=n-i+1;j--)
				sum=(sum*j)%mod;
			for(int j=i;j>=1;j--)
				sum=(sum*mod)/j%mod;
		}
		cout<<sum<<'\n';
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	stable_sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
