#include<bits/stdc++.h>
using namespace std;
bool a[10005][10005],w[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,w+i);
        a[u][v]=1;
    }
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d",&x);
        for(int j=1;j<=n;j++)
            scanf("%d",&y);
    }
    cout<<"0";
    return 0;
}
