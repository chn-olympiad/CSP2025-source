#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=998244353;
ll n,m,t,k,f,s,a[32767],b[32767],c[32767];
ll dfs(ll x,ll y,ll ii,ll ans)
{
	if(x==k)
	{
		if(ans>y*2)
			return 1;
		else
			return 0;
	}
	if(c[x]!=-1)
		return c[x];
	ll fs=0,ma=0;
	for(ll i=ii; i<=n; i++)
	{
		ma=max(y,max(a[i],a[ii]));
		c[x]=1;
		fs=(fs+dfs(x+1,ma,i+1,ans+a[i]))%M;
		c[x]=-1;
		ma=0;
	}
	return fs;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1; i<=n; i++)
		cin>>a[i];
	if(n==3)
	{
		sort(a+1,a+1+n);
		for(ll i=1; i<=n; i++)
			b[i]=b[i-1]+a[i];
		if(b[n]-b[0]>a[n]*2)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	k=3;
	while(k<=n)
	{
		memset(c,-1,sizeof(c));
		s=(s+dfs(0,0,1,0))%M;
		k++;
	}
	cout<<s%M;
	return 0;
}
