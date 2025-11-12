#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n,w[1000005],c[1000005],a[10][10005],m,k,ans;
map<pair<int,int>,int>mp;
vector<int>g[10005],ansl;
void dfs(int a,int b,int fa,int cnt)
{
    if(cnt==0)
    {
        if(a==b)
            ansl.push_back(ans);
        return;
    }
    for(auto v : g[a])
    {
        if(v==fa)continue;
        ans+=mp[make_pair(a,v)];
        dfs(v,b,a,cnt-1);
        ans-=mp[make_pair(a,v)];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        mp[make_pair(u,v)]=w;
        mp[make_pair(v,u)]=w;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    dfs(1,n,0,n);
    int mi=INT_MAX;
    for(int v:ansl)
    {
        mi=min(mi,v);
    }
    cout<<mi<<endl;
}


