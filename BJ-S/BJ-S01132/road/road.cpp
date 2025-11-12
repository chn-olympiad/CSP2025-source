#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],t,ans;
struct node
{
    int vi;
    int wi;
};
vector<node> v[10005];
void dfs(int a,int b)
{
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,vv,w;
        cin>>u>>vv>>w;
        v[u].push_back({vv.w});
        v[vv].push_back({u.w});
    }
    t=n+1;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int a;
            cin>>a;
            v[t].push_back({j.a});
            v[j].push_back({t.a});
        }
        t++;
    }
    dfs(1);
    return 0;
}
