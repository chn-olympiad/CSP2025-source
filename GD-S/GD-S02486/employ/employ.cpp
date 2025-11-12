#include <bits/stdc++.h>
using namespace std;
int n,m,a[510],p[510];
long long ans;
string s;
bool vis[510];
void dfs(int u,int ref)
{
	if(u>n)
	{
		if(n-ref>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(a[i]<=ref||s[u-1]=='0')
			{
				vis[i]=1;
				dfs(u+1,ref+1);
				vis[i]=0;
			}else
			{
				vis[i]=1;
				dfs(u+1,ref);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
