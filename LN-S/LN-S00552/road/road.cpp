#include<bits/stdc++.h>
using namespace std;
long long a[10005][10005];
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        ans+=w;
    }
    cout<<ans;
    return 0;
}
