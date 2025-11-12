#include<bits/stdc++.h>
using namespace std;
int c[510],vis[500],mp[500];
int n,m,ans=0;
string s1;
void dfs(int dep)
{
	if(dep>n)
	{
		int cnt=0,o=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=mp[i]) 
			{
				cnt++;
				continue;
			}
			if(s1[i-1]=='1') o++;
			else cnt++;
		}
		if(o>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		mp[dep]=c[i];
		vis[i]=1;
		dfs(dep+1);
		vis[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=18)
	{
		dfs(1);
		cout<<ans;		
	}
	else
	{
		cout<<0;
	}
	return 0;
}
