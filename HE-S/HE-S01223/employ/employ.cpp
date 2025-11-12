#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int c[1000];
int ans[1000];
int vis[1000];
string a;
int cnt=0;
int dfs(int s)
{
	if(s>n)
	{
		int nf=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i-1]=='0')
			{
				nf++;
			}
			else
			{
				if(nf>=c[ans[i]])
				{
					nf++;
				}
			}
		}
		if(n-nf>=m)cnt++;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		ans[s]=i;
		dfs(s+1);
		vis[i]=0;
	}
	return 0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<cnt;
}
