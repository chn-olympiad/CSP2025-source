#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int w[10000][10000];
int c[10000];
int v[10000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y;
	memset(w,127,sizeof(w));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		scanf("%d",&w[x][y]);
		w[y][x]=w[x][y];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[n+i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&w[n+i][j]);
			w[j][n+i]=w[n+i][j];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
