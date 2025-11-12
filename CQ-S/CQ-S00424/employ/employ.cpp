#include <bits/stdc++.h>
using namespace std;
const int MAXN=20;
const int mod=998244353;
int a[MAXN];
int can[MAXN];
int ans=0;
int n,m;
int vis[MAXN];
void dfs(int step,int k,int cnt)
{
	if(step>n)
	{
		if(k>=m) ans=(ans+1%mod);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(cnt>=can[i]) dfs(step+1,k,cnt+1); 
		else
		{
			if(a[step]==0) dfs(step+1,k,cnt+1);
			else dfs(step+1,k+1,cnt);
		}
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++) cin>>can[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

