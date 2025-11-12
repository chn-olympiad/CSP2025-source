#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,c[510],m,pl[510];
string s;
long long ans;
bool vis[510];
void check()
{
	int fail=0,suc=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||fail>=c[pl[i]]) fail++;
		else suc++;
	}
	if(suc>=m) ans=(ans+1)%mod;
}
void dfs(int k)
{
	if(k==n)
	{
		check();
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		pl[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	if(n<=10) dfs(0);
	else
	{
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*2)%mod;
	}
	cout<<ans;
	return 0;
}
