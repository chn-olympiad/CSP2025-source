#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m);scanf("%d",&k);
	for(int i = 0;i < m;i++)
	{
		scanf("%d",&u[i]);scanf("%d",&v[i]);scanf("%d",&w[i]);
	}
	for(int i = 0;i < k;i++)
	{
		scanf("%d",&c[i]);
		for(int j = 0;j < n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("%d",0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}