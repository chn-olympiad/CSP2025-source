#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],ans;
bool f[510];
char s[510];
void dfs(int d,int sum,int l)
{
	if(d>n)
	{
		if(sum>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)continue;
		f[i]=1;
		if(c[i]<=l)dfs(d+1,sum,l+1);
		else
		{
			if(s[d]==0)dfs(d+1,sum,l+1);
			if(s[d]==1)dfs(d+1,sum++,l);
		}
		f[i]=0;
	}
}
int main()
{
	//freopen("employ.in", "r", stdin);
	//freopen("employ.out", "w", stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
