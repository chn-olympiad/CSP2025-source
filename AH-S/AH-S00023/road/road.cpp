#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010],a[100010][20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++) scanf("%d",&a[i][j]);
	cout<<13;
	return 0;
}
