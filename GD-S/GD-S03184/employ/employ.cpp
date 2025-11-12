#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=1e6+10,R=998244353;
ll n,m;
string s;
ll c[N];
ll ans,pl[N];
bool chk()
{
	ll giveup=0;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='0') giveup++;
		else if(giveup>=c[pl[i]])
		  giveup++;
	}
	return n-giveup>=m;
}
bool v[N];
void dfs(ll p)
{
	if(p==n)
	{
		if(chk())
		{
			ans++;
			return;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(v[i]) continue;
		pl[p]=i;
		v[i]=true;
		dfs(p+1);
		v[i]=false;
	}
}
void solvee()
{
	ans=1;
	for(ll i=1;i<=n;i++)
	  ans=(ans*i)%R;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(ll i=1;i<=n;i++)
	scanf("%lld",&c[i]);
	bool f1=true;
	for(ll i=0;i<n;i++)
	 if(s[i]=='0') f1=false;
	if(f1) solvee();
	else
	  dfs(0);
	printf("%lld",ans);
	return 0;
}
