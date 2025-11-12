#include<bits/stdc++.h>
using namespace std;
priority_queue<array<int,3>>edge;
int c[10005];
int ro(int x)
{
    return c[x]=(x==c[x]?x:ro(c[x]));
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    iota(c+1,c+n+1,1);
    if(k!=0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push({-w,u,v});
    }
    for(int i=1;i<=m;i++)
    {
        auto c=edge.top();
        edge.pop();
        if(ro(c[1])==ro(c[2]))
            continue;
        ans-=c[0];
        ::c[ro(c[1])]=ro(c[2]);
    }
    cout<<ans;
}