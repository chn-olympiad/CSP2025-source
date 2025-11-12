#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],ans,dick[10005];
const long long mod=998244353;
void dfs(long long cnt,long long x,long long sum,long long f)
{
	if(cnt==f)
	{
		if(sum>dick[f]*2)
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(long long i=x+1;i<=n;i++)
	{
		dick[cnt+1]=a[i];
		dfs(cnt+1,i,sum+a[i],f);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(0,0,0,i);
	}
	cout<<ans;
	return 0;
}
