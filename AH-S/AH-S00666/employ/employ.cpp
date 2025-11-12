#include<bits/stdc++.h>
using namespace std;
bool vis[505];
bool b=true;
int n,m;
int a[505];
int s[505];
int ans=0;
void dfs(int now,int sum)
{
	if(now==n+1&&sum>=m)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==false)
		{
			int ss=0;
			vis[i]=true;
			if(s[now]==0)
			for(int j=1;j<=n;j++)
			if(vis[j]==false)
			a[j]--,ss++;
			if(a[i]<=0||s[now]==0)
			dfs(now+1,sum);
			else
			dfs(now+1,sum+1);
			for(int j=1;j<=n;j++)
			if(vis[j]==false)
			a[j]++,ss--;
			vis[i]=false;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
