#include<bits/stdc++.h>
using namespace std;
int b[100005],bb[15][10005];
struct Node
{
    int u,v,w;
}a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;


    }
    int ans=0;
     for(int i=1;i<=k;i++)
    {
        cin>>b[i];
       for(int j=1;j<=m;j++)cin>>bb[i][j];
    }
    int l=0;

     for(int i=1;i<=m;i++)
    {
        int minn=1000000005;
        for(int j=1;j<=k;j++)minn=min(minn,b[j]+bb[j][a[i].u]+bb[j][a[i].v]);
        ans+=min(a[i].w,minn);
    }
    cout<<ans;
    return 0;
}

