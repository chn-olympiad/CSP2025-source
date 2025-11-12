#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const int mod=998244353;
ll n,m,ans;
ll c[N],q[N];
bool f[N],b;
char a[N];
bool check()
{
	ll s=0,g=0;
	for(ll i=1;i<=n;i++)
	{
		if(c[q[i]]<=s)
		{
			s++;
			continue;
		}
		if(a[i]=='1')
		{
			g++;
		}
		else
		{
			s++;
		}
	}
	return g>=m;
}
void hold()
{
	for(ll i=1;i<=n;i++)
	{
		if(a[i]=='0')
		{
			b=1;
		}
	}
	if(b==0)
	{
		ll eans=1;
		for(ll i=1;i<=n;i++)
		{
			eans*=i;
			eans%=mod;
		}
		cout<<eans;
	}
	else
	{
		cout<<0;
	}
	exit(0);
}
void dfs(ll x)
{
	if(x==n+1)
	{
		if(check())
		{
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(ll i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			q[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>a+1;
	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			b=1;
		}
	}
	if(m==n) hold();
	dfs(1);
	cout<<ans;
	return 0;
}
