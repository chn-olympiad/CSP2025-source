#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int minn=1e9;
int ans;
int c[1000000][1000000];
struct Node{
    int u,v,w;
}a[100000];
int b[100000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
    for(int j=0;j<3;j++)
    {
        for(int i=0;i<m;i++)
        {
            minn=min(minn,a[i].w);

            ans+=minn;
        }
    }
    cout<<ans;
    return 0;
}

