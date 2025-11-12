#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c[15];
string s;
int vis[15];
void dfs(int dep,int sum)
{
	if(dep>=n+1)
	{
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(sum>=c[i])sum++;
			if(s[dep]=='0')sum++;
			dfs(dep+1,sum);
			if(sum>=c[i])sum--;
			if(s[dep]=='0')sum--;
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)
	{
		dfs(1,0);
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
