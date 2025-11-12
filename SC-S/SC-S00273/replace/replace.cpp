#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e3+100;
int n,q;
string a[2][MAXN];
string que[2][MAXN];
int len;
bool vis[2][MAXN][MAXN];
int l[2][MAXN];
int lst[MAXN<<1];
string tmp;
int tt;
ll ans;
int st,en;
void kmp(int x,int y,int ind)
{
	len=a[ind][x].length()+que[ind][y].length()+1;
	tmp=a[ind][x]+'#'+que[ind][y];
	memset(lst,0,sizeof(lst));
	for(int i=1;i<len;++i)
	{
		int j=lst[i-1];
		while(j&&tmp[i]!=tmp[j])j=lst[j-1];
		if(tmp[i]==tmp[j])++j;
		lst[i]=j;
	}
	for(int i=l[ind][x]+1;i<len;++i)
	{
		if(lst[i]==l[ind][x])vis[ind][x][i-l[ind][x]-1]=1;
		else vis[ind][x][i-l[ind][x]-1]=0;
	}
}
void solve(int x)
{
	for(int i=1;i<=n;++i)
	{
		kmp(i,x,0);
		kmp(i,x,1);
	}
	len=que[0][x].length();
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=0;j<len;++j)cout<<vis[1][i][j];
//		cout<<endl;
//	}
//	return;
	st=en=0;
	for(int i=0;i<len;++i)
	{
		if(que[0][x][i]!=que[1][x][i])
		{
			st=i;
			break;
		}
	}
	for(int i=len-1;i>=0;--i)
	{
		if(que[0][x][i]!=que[1][x][i])
		{
			en=i;
			break;
		}
	}
	if(!st||!en)
	{
		cout<<0<<'\n';
		return;
	}
	ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=len-1;j>=en;--j)
		{
			if(vis[0][i][j]&&vis[1][i][j]&&i-l[0][i]<st)++ans;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[0][i]>>a[1][i];
	for(int i=1;i<=q;++i)cin>>que[0][i]>>que[1][i];
	for(int i=1;i<=n;++i)l[0][i]=a[0][i].length(),l[1][i]=a[1][i].length();
//	for(int i=1;i<=n;++i)cout<<l[1][i]<<endl;
	for(int i=1;i<=q;++i)solve(i);
	return 0;
}