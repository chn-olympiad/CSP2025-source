#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int ans;
int minn=0x3f3f3f;
struct node
{
    int u,v;
};
int a[10005][10005];
int c[1005];
vector<node>edges[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    if(k<=0)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
        minn=min(minn,c[i]);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ans+=a[i][j];
        }
    }
    cout<<ans+minn;
    return 0;
}
