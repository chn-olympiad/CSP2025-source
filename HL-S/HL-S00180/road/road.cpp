#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,m,k;
int u[1000005],v[1000005],w[1000005];
int c[1000005],a[1005][1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	sort(u+1,u+1+m);
	sort(v+1,v+1+m);
	sort(w+1,w+1+m);
	cout<<u[1]+v[1]+w[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}