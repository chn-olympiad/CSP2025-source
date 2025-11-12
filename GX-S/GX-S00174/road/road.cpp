#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],b[1001][1001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,u,v,w,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
        b[u][v]=1;
        b[v][u]=1;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>
    };
    srand(time(0));
    cout<<rand();
    return 0;
}
