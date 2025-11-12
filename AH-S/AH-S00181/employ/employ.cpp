#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
int n,m;
LL ans;
string s;
int c[505];
bool vis[505];
void dfs(int cnt,int t)
{
	if(t==n)
	{
		if(cnt>=m) ans++,ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(t-cnt>=c[i]||s[t]=='0') dfs(cnt,t+1);
			else dfs(cnt+1,t+1);
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(0,0);
	cout<<ans%MOD;
	return 0;
}
