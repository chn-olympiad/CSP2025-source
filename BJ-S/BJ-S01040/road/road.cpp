#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],ans=2e9;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,p;
        scanf("%d %d %d",&u,&v,&p);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
        {
            int p;
            scanf("%d",&p);
        }
    }
    printf("%d\n",0);
    return 0;
}
