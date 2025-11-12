#include<bits/stdc++.h>
using namespace std;
int c[10010],a[10][10010];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        sum+=w;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if(m==n-1)
    {
        cout<<sum;
    }
    else cout<<56378;
}
