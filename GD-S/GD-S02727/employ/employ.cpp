#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,ans;
string difcut;
int c[1005];
int p[1005];
bool vis[1005];
void check()
{
	int no=0;
	for(int i=1;i<=n;i++)
		if(difcut[i]=='0' || no>=c[p[i]])no++;
	if(n-no>=m)ans=(ans+1)%mod;
	return ;
}
void dfs(int id)
{
	if(id==n+1)
	{
		check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		p[id]=i;
		dfs(id+1);
		vis[i]=p[id]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>difcut;difcut=" "+difcut;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
