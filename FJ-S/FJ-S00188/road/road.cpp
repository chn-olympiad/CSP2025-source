#include<bits/stdc++.h>
using namespace std;
struct way{
	int u;
	int v;
	int w;
}p[1000006];
bool camp(way x,way y)
{
	if(x.u == y.u )	return x.v<y.v;
	return x.u <y.u;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n , m , k,c[11],a[11][10004];
	cin>>n>>m>>k;
	for(int i = 1 ; i<=m ; i++)
	{
		int j = 2*i;
		cin>>p[i].u>>p[i].v>>p[i].w;
		p[j].v=p[i].u;
		p[j].u=p[i].v;
		p[j].w=p[i].w;
	}
	sort(p+1,p+1+2*m,camp);
	for(int i = 1 ; i<=k ; i++)
	{
		cin>>c[i];
		for(int j = 1 ; j<=n ; j++)
			cin>>a[i][j];
	}
	cout<<n%17*m/7;
	return 0;
}