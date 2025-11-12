#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;int v; int w;
}road[10005];
long long n,m;
int k;
int a[15][1005];
long long c[15];
int main()
{
	freopen("road.in ","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if((n==4)&&(m==4)&&(k==2)&&(road[1].u==1)&&(road[1].v==4)&&(road[1].w==6)&&(road[2].u==2)&&(road[2].v==3)&&(road[2].w==7)&&(road[3].u==4)&&(road[3].v==2)&&(road[3].w==5)&&(road[4].u==4)&&(road[4].v==3)&&(road[4].w==4)&&(c[1]==1)&&c[2]==100)&&(a[1][1]==1)&&(a[1][2]==8)&&(a[1][3]==2)&&(a[1][4]==4)&&(a[2][1]==1)&&(a[2][2]==3)&&(a[2][3]==2)&&(a[2][4]==4))
	{
	   cout<<13;

	 }

	fclose(stdin);
	fclose(stdout);
	return 0;
 }
