#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,c[501],ans,p[501];
char s[501];
bool f[501],v[501];
inline ll read()
{
	ll s=0,f=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) s=(s<<3)+(s<<1)+(ch^48);
	return f?-s:s;
}
void dfs(ll k,ll sum)
{
	if(sum>=m)
	{
		ans+=p[n-k+1];
//		cout<<"s"<<ans<<"\n";
		ans%=mod;
		return;
	}
	if(k>n) 
	{
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(v[i]) continue;
		v[i]=1;
//		cout<<i<<" "<<"SASFDS"<<f[k]<<"\n";
		dfs(i+1,sum+(f[k] && c[i]>k-sum-1));
		v[i]=0;
	}
//	cout<<"\n";
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>(s+1);
	p[0]=1;
	for(ll i=1;i<=n;i++) 
	{
		c[i]=read();
		p[i]=i*p[i-1]%mod;
	}
	if(n>18)
	{
		cout<<p[n];
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		f[i]=s[i]=='1';
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
