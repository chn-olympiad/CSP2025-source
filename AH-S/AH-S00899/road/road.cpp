#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1005][1005];
int u,v,w,sum;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        scanf("%d",&a[u][v]);
        a[v][u]=a[u][v];
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=0;i<=n;i++)
        {
            int x;
            scanf("%d",x);
            if(a[j][i]==0)a[j][i]=x;
            a[j][i]=min(a[j][i],x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum+=min(a[i][j],a[j][i]);
        }
    }
    printf("%d",sum);
    return 0;
}

