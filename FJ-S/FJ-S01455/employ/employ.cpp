#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m; int s[60];
bool vis[60];
int c[60];ll ans=0;
inline ll Fac(ll X)
{
	ll res=1;
	for(ll i=2;i<=X;i++) res=(res*i)%mod;
	return res;
}
inline void dfs(int u,int Rst)
{
	if(Rst<0) return;
	if(u==n+1){ans=(ans-1+mod)%mod; return;}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=true;
//		cout<<u<<" "<<i<<"\n";
		if(s[u]<c[i]) dfs(u+1,Rst-1);
		else dfs(u+1,Rst);
		vis[i]=false;
	}
	return;
}
inline void solve()
{
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		char x; cin>>x;
		if(x=='0') s[i]=s[i-1]+1;
		else s[i]=s[i-1];
//		cout<<s[i]<<" ";
	}
//	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		c[i]--;
//		cout<<c[i]<<" ";
	}
//	cout<<"\n";
	ll ans=0;
	if(n<=18) dfs(1,m);
	ans=(ans+Fac(n))%mod;
//	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	solve();
	return 0;
}
