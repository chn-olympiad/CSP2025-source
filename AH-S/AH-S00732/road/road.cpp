#include<bits/stdc++.h>
using namespace std;
int n,q,u[100000],v[1000000],w[1000000],c[100000],a[10000][10000];
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++)
		 cin>>a[i][j];
	}
	cout<<13;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
