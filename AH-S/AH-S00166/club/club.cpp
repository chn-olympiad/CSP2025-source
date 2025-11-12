#include<bits/stdc++.h>
using namespace std;
int a[100100][4],b[100100],n,maxn,c[4];
void dfs(int i,int v)
{
	if(i>n)
	{
		maxn=max(maxn,v);
		return ;
	}
	if(c[1]<(n/2))
	{
		c[1]++;
		dfs(i+1,v+a[i][1]);
		c[1]--;
	}
	
	if(c[2]<(n/2))
	{
		c[2]++;
		dfs(i+1,v+a[i][2]);
		c[2]--;
	}
	
	if(c[3]<(n/2))
	{
		c[3]++;
		dfs(i+1,v+a[i][3]);
		c[3]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				a[i][j]=0;
			}
		}
		memset(c,0,sizeof(c));
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<maxn<<'\n';
	}
	return 0;
}
