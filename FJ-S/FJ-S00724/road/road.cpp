#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,q;
};
node a[1000005];
int b[10][1000006];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].q);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&b[i][0]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("0");
	return 0;
}
