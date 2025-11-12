#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w[1000005],c[1000005];
long long ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w[i];
    }
    sort(w+1,w+1+m);
    for(int i=1;i<n;i++)
    {
        ans+=w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
    }
    cout<<ans;
    return 0;
}
