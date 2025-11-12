#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=600;
const int mod=998244353;
int n,m;
string s;
int c[maxn];
int vis[maxn];
int ans=0;
void dfs(int step,int de,int cnt)
{
	if(step>n)
	{
		if(cnt>=m)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(s[step]=='1'&&c[i]>de) dfs(step+1,de,cnt+1);
		else if(s[step]=='1'&&c[i]<de) dfs(step+1,de+1,cnt);
		else if(s[step]=='0') dfs(step+1,de+1,cnt);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s="0"+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
}
