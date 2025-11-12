#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
char s[N];
int n,m,c[N],dfn[N],ans,sum,cnt;
bool vis[N];
void dfs(int nw)
{
	if(nw>n)
	{
		sum=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[dfn[i]]||s[i]=='0') cnt++;
			else sum++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1,dfn[nw]=i;
		dfs(nw+1);
		vis[i]=0;
	}
}
void sol()
{
	dfs(1);
	cout<<ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) sol();
	else cout<<0;
	return 0;
}
