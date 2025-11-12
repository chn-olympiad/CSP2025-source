#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int c[N];
string s;
int vis[N],n,ans,m;
void dfs(int u,int cnt,int qi)
{
	if(u==n+1||cnt>=m)
	{
		ans+=(cnt>=m);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		if(qi>=c[i]||s[u-1]=='0')dfs(u+1,cnt,qi+1);
		else dfs(u+1,cnt+1,qi);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}