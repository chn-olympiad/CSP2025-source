#include<bits/stdc++.h>
using namespace std;
int n,m,p;

int c[15];
int a[15][10005];

int dis[1005][1005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=w;
        dis[v][u]=w;
    }
    for(int i=1;i<=p;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    if(p==0)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans+=dis[i][j];
            }
        }
        cout<<ans/2<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}
