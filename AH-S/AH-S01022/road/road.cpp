#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct cmp;
struct edge
{
    int u,v,w;

    bool operator<(edge a)
    {
        return w<a.w;
    }
    friend class cmp;
};
struct cmp
{
    bool operator()(edge a,edge b)
    {
        return a.w>b.w;
    }
};
vector<edge> edges[10010];
bool vis[10010];
void run()
{
    int n,m,k,u,v,w;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
		edges[u].push_back({u,v,w});
		edges[v].push_back({v,u,w});
    }
    priority_queue<edge,vector<edge>,cmp> pq;
    for(auto&i:edges[1])
    {
        pq.push(i);
    }
    vis[1]=true;
    int cnt=0;
    ll ans=0;
    while(cnt<n-1)
    {
        edge tp=pq.top();
        //cout<<tp.u<<" "<<tp.v<<" "<<tp.w<<"\n";
        pq.pop();
        if(vis[tp.u]&&vis[tp.v]) continue;
        if(!vis[tp.u])
        {
            for(auto&i:edges[tp.u])
            {
                pq.push(i);
            }
        }
        if(!vis[tp.v])
        {
            for(auto&i:edges[tp.v])
            {
                pq.push(i);
            }
        }
        vis[tp.u]=vis[tp.v]=true;
        ans+=tp.w;
        cnt++;
    }
    cout<<ans;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t=1;
    while(t--)
    {
        run();
        cout<<"\n";
    }

    return 0;
}
/*

*/
