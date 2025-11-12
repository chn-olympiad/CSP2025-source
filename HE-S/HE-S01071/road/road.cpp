#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road
{
	int u,v,w;
} r[100010];
struct j
{
	int a;
	int jn[1010];
} town[11];
int main()
{
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d,%d,%d",&r[i].u,&r[i].v,&r[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>town[i].a;
		for(int j=1;j<=n;j++)
		{
			cin>>town[i].jn[j];
		}
	}
	return 0;
}
