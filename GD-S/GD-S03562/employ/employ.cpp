#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353,NR=501;
char s[NR];
bool vis[NR];
int n,m,ans,c[NR];
void dfs(int d,int x)
{
	if(n-x<m) return;
	if(d==n+1)
	{
		ans++;
		return;
	}
	int i;
	if(s[d]=='1')
	{
		for(i=1;i<=n;i++)
			if(!vis[i])
			{
				vis[i]=true;
				if(x>=c[i]) dfs(d+1,x+1);
				else dfs(d+1,x);
				vis[i]=false;
			}
	}
	else
		for(i=1;i<=n;i++)
			if(!vis[i])
			{
				vis[i]=true;
				dfs(d+1,x+1);
				vis[i]=false;
			}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,cnt=0;
	cin>>n>>m;
	bool f=true;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]!='1') f=false;
	}
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		cnt+=(s[i]!=0 && c[i]!=0);
	}
	if(cnt<m)
	{
		cout<<0;
		return 0;
	}
	if(f && n>=30)
		for(i=1;i<=n;i++) ans=ans*i;
	else dfs(1,0);
	cout<<ans;
	return 0;
}
