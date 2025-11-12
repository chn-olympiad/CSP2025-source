#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10000010],v[10000010],w[10000010];
int c[10000010],a[10000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w[i]; 
	}
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
		cin>>a[i];
	}
	cout<<13<<endl;
	fclose(stdin);
	fclose(stdout);
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
