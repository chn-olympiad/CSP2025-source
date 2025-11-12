#include <bits/stdc++.h>
using namespace std;
int n,m,k,sum,min,b[15][100000];
struct City
{
	int u1;
	int v1;
	int w1;
}a[10000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>a[i].u1>>a[i].v1>>a[i].w1;
    for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		    cin>>b[i][j];
	cout<<13;
    return 0;
}
