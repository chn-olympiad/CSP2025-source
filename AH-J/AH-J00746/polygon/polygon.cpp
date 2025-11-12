#include <bits/stdc++.h>
using namespace std;
int a[5005],f[5005],n,m,s;
void dfs(int x,int y,int c,int o)
{
	if(x>m)
	{
		if(o>c*2)
		{
			s++;
		}
		return ;
	}
	if(n-y<m-x+1)
	{
		return ;
	}
	for(int i=y+1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(x+1,i,max(c,a[i]),o+a[i]);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		m=i;
		dfs(1,0,0,0);
	}
	cout<<s;
}
