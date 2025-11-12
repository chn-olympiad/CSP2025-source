#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
vector<long long> lst;
vector<long long> fac;
long long func_c(int n,int k)
{
	return fac[n]/fac[k]/fac[n-k];
}
void solve1()
{
	fac.resize(n+1);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		ans=(ans+func_c(n,i))%mod;
	}
	cout<<ans;
}
long long cnt,mx,sum,sum2;
vector<long long> pw;
long long dfs(int x)
{
	if(x==n)
	{
		return (cnt>=3&&sum>2*mx?1:0);
	}
	long long ex=mx;mx=max(mx,lst[x]);
	sum2+=lst[x];
	long long ans;
	if(sum2>2*mx) ans=pw[n-x-1]%mod;
	else ans=dfs(x+1)%mod;
	sum2-=lst[x];
	mx=ex;
	cnt--;
	sum-=lst[x];
	if(cnt>=3&&sum>2*mx) ans=(ans+dfs(x+1))%mod;
	cnt++;
	sum+=lst[x];
	return ans;
}
void solve2()
{
	sort(lst.begin(),lst.end(),greater<int>());
	for(int i=0;i<n;i++) sum+=lst[i];
	pw.resize(n+1);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	cnt=n;
	cout<<dfs(0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;lst.resize(n);
	long long mx=0;
	for(int i=0;i<n;i++)
	{
		cin>>lst[i];
		mx=max(mx,lst[i]);
	}
	if(mx==1) solve1();
	else solve2();
	return 0;
}
