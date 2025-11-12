#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int w[10010],u[10010],v[10010],c[10010];
int a[10010][10010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans;
	ans=0;
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	
	return 0;
}

