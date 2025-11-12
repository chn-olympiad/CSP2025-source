#include<bits/stdc++.h>
using namespace std;
const int N=105;
bool flg[N];
char s[N];
int c[N],p[N];
int dfs(int n,int m,int now)
{
	if(now==n+1)
	{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||cnt1>=c[p[i]])cnt1++;
			else cnt2++;
		}
		if(cnt2>=m)return 1;
		return 0;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(flg[i])continue;
		flg[i]=true,p[now]=i;
		res+=dfs(n,m,now+1);
		flg[i]=false;
	}
	return res;
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	cout<<dfs(n,m,1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	for(;T;T--)solve();
	return 0;
}
