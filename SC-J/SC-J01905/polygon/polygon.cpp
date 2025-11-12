#include<bits/stdc++.h>
using namespace std;
//#define int long long
const long long mod=998244353;
const long long N=5050;
long long n,a[N],ans,f[N];
void dfs(long long bs,long long k,long long sum,long long x)
{
	if(sum>x)
	{
		if(bs>=3)
		{
			ans+=f[k];
			ans%=mod;
			return ;		
		}
	}
	for(long long i=1;i<=k;i++)
	{
		dfs(bs+1,i-1,sum+a[i],x);
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool flag=true;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	f[0]=1;
	for(long long i=1;i<=n;i++)f[i]=(f[i-1]*2)%mod;
	if(flag)
	{
		cout<<(f[n]-1-n-((n-1)*n)/2+mod)%mod;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n>20)
	{
		for(long long i=3;i<=n;i++)
		{
	//		cout<<i<<"\n";
			if(i!=n && a[i+1]==a[i])continue;
			dfs(1,i-1,0,a[i]);
		}
		cout<<ans;
	}
	else
	{
		for(long long i=3;i<=n;i++)
		{
	//		cout<<i<<"\n";
			dfs(1,i-1,0,a[i]);
		}
		cout<<ans;
	}
	return 0;
}

