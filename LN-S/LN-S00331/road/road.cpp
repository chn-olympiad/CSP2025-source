#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
int u[1000001];
int v[1000001];
int w[1000001];
int c[11][100001];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    printf("%d",n+m+k);
    printf("\n");
    return 0;
}