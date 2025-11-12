#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10015][10015],b[15][10015];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        a[x][y]=a[y][x]=z;
    }
    forr(int i=1;i<=k;i++)
    {
        for(int j=0;j>=n;j++) scanf("%d",&b[i][j]);
    }

    return 0;
}
