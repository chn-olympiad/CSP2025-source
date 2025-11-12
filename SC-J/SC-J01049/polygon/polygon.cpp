#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
vector<long long>a,st;
long long n,ans;
void dfs(long long now)
{
	if(now>n)
	{
		long long maxn=0,sum=0,cnt=0;
		for(long long i=1;i<=n;i++)
			if(st[i]==1)
			{
				cnt++;
				maxn=max(maxn,a[i]);
				sum+=a[i];
			}
		if(sum>maxn*2&&cnt>=3)ans=(ans+1)%mod;
		return;
	}
	for(long long i=0;i<=1;i++)
	{
		st[now]=i;
		dfs(now+1);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	st=a=vector<long long>(n+10);
	long long cnt=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)cnt++;
	}
	if(cnt==n)
	{
		long long sum=1;
		for(long long i=1;i<=n;i++)
			sum=(sum*2)%mod;
		ans=sum-((n*(n-1)/2)%mod)-n-1;
	}
	else dfs(1);
	cout<<ans;
	return 0;
}