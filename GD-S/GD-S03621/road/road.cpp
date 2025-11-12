#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s;
int u,v;
long long w[10010][10010];
int c[20];
int ct[20][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w[u][v];
		s+=w[u][v]; 
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&ct[i][j]);
		}
	}
	printf("%lld",s);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
