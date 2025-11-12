#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],b[15][1010],c[1010];
int n,m,k;
int ans=1e9;
void dfs(int step,int last,int sum)
{
	if (step==n+1)
	{
		ans=min(sum,ans);
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (c[i]==0)
		{
			c[i]=1;
			dfs(step+1,i,sum+a[last][i]);
			c[i]=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for (int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for (int j=1;j<=n;j++)
		{
			
			cin>>b[i][j];
			for (int f=1;f<=j-1;f++)
			{
				if (b[i][f]+b[i][j]+x<a[f][j])
				{
					a[f][j]=b[i][f]+b[i][j]+x;
					a[j][f]=b[f][j];
				}
			}
		}
		
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=n;j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	c[1]=1;
	dfs(2,1,0);
	cout<<ans;
	return 0;
 } 
 //Ren5Jie4Di4Ling5%
