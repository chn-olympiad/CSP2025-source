#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[510];
int c[510],d[510][1000],cf[510];

void dfs(int i,int mt,int tl)
{
	if(i>n)
	{
		if(tl>=m)
		{
			ans++;
		}
		return;
	}
	if(c[i]<=mt)
	{
		dfs(i+1,mt+1,tl);
	}
	if(a[i]==1)
	{
		dfs(i+1,mt,tl+1);
	}
	else dfs(i+1,mt+1,tl);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		cf[i]=i;
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
	{
		d[i][1]=cf[i];
	}
	int w=1;
	bool pd=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			pd=1;
			int tem=cf[j];
			cf[j]=cf[i];
			cf[i]=tem;
			int tem2=c[j];
			c[j]=c[i];
			c[i]=tem2;
			for(int k=1;k<=w;k++)
			{
				for(int fs=1;fs<=n;fs++)
				{
					if(d[k][fs]==cf[fs])
					{
						pd=0;
						break;
					}
				}
			}
			if(pd)
			{
				dfs(1,0,0);
				w++;
				for(int k=1;k<=n;k++)
				{
					d[w][i]=cf[i];
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
