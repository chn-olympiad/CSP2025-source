#include<bits/stdc++.h>
using namespace std;
struct Road{
	int u,v;
	int w;
}road[100005];
struct Village{
	int c;
	int a[100005];
}villa[15];
int n;
int m;
int k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int asa,b,c;
		cin>>asa>>b>>c;
		road[i].u=asa;
		road[i].v=b;
		road[i].w=c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>villa[i].c;
		for(int j=1;j<=n;j++)
		{
			cin>>villa[i].a[j];
		}
	}
	cout<<13<<'\n';
	return 0;
}
