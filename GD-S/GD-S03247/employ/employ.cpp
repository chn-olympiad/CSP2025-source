#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=506,mod=998244353 ;
int n,a[maxn],ans,m;
bool vis[maxn];
string s;

void dfs(int x,int q)
{
	if(x==n+1)
	{
		if(n-q>=m) ans=(ans+1)%mod;
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(s[x-1]=='0'|| q>=a[i]) q++;
		dfs(x+1,q);
		vis[i]=0;
		if(s[x-1]=='0'||q-1>=a[i]) q--;
	}
	return;
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	memset(vis,0,sizeof vis);
	dfs(1,0);
	
	cout<<ans;
	
	
	
	return 0;
}
