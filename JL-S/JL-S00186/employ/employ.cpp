#include <bits/stdc++.h>
using namespace std;
int ss[1145141],c[1145141];
int n,m;
int a[1145141];
int ans=0;
bool vis[1145141];
void dfs(int x,int s)
{
	if(x==n+1)
	{
		if(s<=(n-m))ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if((!ss[x])||c[i]<=s)dfs(x+1,s+1);
			else dfs(x+1,s);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string st;
	cin>>st;
	for(int i=0;i<st.size();i++)ss[i+1]=st[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
