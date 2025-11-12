#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100010;
int n,a[MAXN][5],ans;
void dfs(int now,int c1,int c2,int c3,int sco)
{
	if(now>n)
	{
		ans=max(ans,sco);
		return ;
	}
	if(c1+1<=(n>>1))
		dfs(now+1,c1+1,c2,c3,sco+a[now][1]);
	if(c2+1<=(n>>1))
		dfs(now+1,c1,c2+1,c3,sco+a[now][2]);
	if(c3+1<=(n>>1))
		dfs(now+1,c1,c2,c3+1,sco+a[now][3]);
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
void solve()
{
	n=read();
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			a[i][j]=read();
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
}
signed main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//ovo qwq awa
	//我要上迷惑行为大赏 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}
