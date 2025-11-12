#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int a[N][N];
int u,v,w;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
        ans+=w;
    }
    cout<<ans;
    return 0;
}
