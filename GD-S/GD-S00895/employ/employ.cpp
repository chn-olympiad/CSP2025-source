#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
char s[505];
int c[505];
bool vis[505];
int sum=0,ans=0;int n,m;
void dfs(int u,int ok)
{
//	cout<<u<<" "<<ok<<endl;
	if(u==n-1)
	{
		if(ok>=m)
		{
			ans++;
		}
		return;
	}
	for(int i= 1; i<= n; i++ )
	{
		if(!vis[i])
		{
			vis[i]=1;
			if((u-ok>=c[i])||(s[i]=='0'))
			{
				dfs(u+1,ok);
			}
			else
			{
//				sum++;
				dfs(u+1,ok+1);
//				sum--;
			}
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i= 1; i <= n; i++ )
	{
		cin>>s[i];
	}
	for(int i= 1; i <= n; i++ )
	{
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans<<endl;
}
