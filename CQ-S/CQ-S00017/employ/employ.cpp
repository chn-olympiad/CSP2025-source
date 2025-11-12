#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int n,m,ans,vis[510],a[510];
string s;

void dfs(int x,int k)
{
	if(k+n-x+1<m) return;
	if(x>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(s[x]=='1'&&x-1-k<a[i]) dfs(x+1,k+1);
		else dfs(x+1,k);
		vis[i]=0;
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
}
