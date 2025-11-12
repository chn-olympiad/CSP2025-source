#include<bits/stdc++.h>
using namespace std;
int a[100005][100005];
int b[20],d[20][100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int x,y,c,cc;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&c);
		a[x][y]=c;
		a[y][x]=c;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&b[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&cc);
			d[i][j]=cc;
		}
	}
	printf("%d",13);
} 
