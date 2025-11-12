#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,c[N],ans,ha;
bool vis[N];
string s;
void dfs(int now,int ge,int sheng)
{
//	if(now==2)cout<<ge<<'n\'
	if(now==n+1)
	{
//		cout<<ha<<' '<<ge<<'\n';
		if(sheng>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		if(s[now-1]=='0')
		{
			dfs(now+1,ge+1,sheng);
			vis[i]=0;continue;
		}
		if(ge<c[i])
			dfs(now+1,ge,sheng);
		else dfs(now+1,ge+1,sheng-1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)ha+=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
//	if(n<=12)
//	{
		dfs(1,0,ha);
		cout<<ans;
		return 0;
//	}
}
