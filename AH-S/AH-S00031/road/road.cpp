#include<bits/stdc++.h>
using namespace std;
long long n,m,k,p[10001],ans,sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(p,127,sizeof(p));
    cin>>n>>m>>k;
    while(m--)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        p[u]=min(p[u],w);
        p[v]=min(p[v],w);
    }
    for(int i=1;i<=n;i++) ans+=p[i];
    while(k--)
    {
        cin>>sum;
        for(int i=1;i<=n;i++)
        {
            long long x;
            cin>>x;
            sum+=min(p[i],x);
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
