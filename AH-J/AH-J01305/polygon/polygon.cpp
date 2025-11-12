#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans,mod=998244353,ans2;
bool f[100005];
void dfs(int cnt,int qu,int sum,int mu,int pos)
{
	if(cnt>qu) return;
	if(sum>=mu)
	{
		ans2++;
	}
	for(int i=pos;i<=qu;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(cnt+1,qu,sum+a[i],mu,i);
			f[i]=0;
		}
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
	sort(a+1,a+n+1);
	if(n==3)
	{
		cout<<((a[1]+a[2]+a[3])>(a[3]*2));
		return 0;
	}
	if(a[n]<=1)
	{
		long long s=1;
		for(int i=1;i<=n;i++)
		{
			s=s*2;
			s=s%mod;
		}
		s=(s-1-n-n*(n-1)/2+mod)%mod;
		cout<<s;
		return 0;
	}
	for(int i=n;i>=3;i--)
	{
		memset(f,0,sizeof(f));
		ans2=0;
		dfs(0,i-1,a[i],2*a[i]+1,1);
		ans+=ans2;
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}
