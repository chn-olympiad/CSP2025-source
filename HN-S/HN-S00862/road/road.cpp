#include<bits/stdc++.h>
using namespace std;
int a[1000][1000],b[1000][1000];
void lu(int x,int y,int p)
{
	if(a[x][y]==0&&a[y][x]==0)
	{
		a[x][y]=p;
	}
	if(a[x][y]!=0)
	{
		if(a[x][y]>=p)
		{
			a[x][y]=p;
		}
	}
	if(a[y][x]!=0)
	{
		if(a[y][x]>=p)
		{
			a[y][x]=p;
		}
	}
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x[1000],y[1000],p[1000],xiu,mon=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i]>>p[i];
		lu(x[i],y[i],p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int o=1;o<=n;o++)
		{
			mon=mon+a[i][o];
		}
	}
	cout<<mon;
	return 0;	
} 
