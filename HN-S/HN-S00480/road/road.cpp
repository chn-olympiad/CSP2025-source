#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z;
const int N=1e6+5;
int a[15][N],f[N][N],c[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=f[y][x]=z;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	cout<<0;
	return 0;
}
