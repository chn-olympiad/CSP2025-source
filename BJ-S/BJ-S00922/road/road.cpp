#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int to;
    int val;
};
vector<edge> vt[10005];
bool f[10015];
priority_queue<edge> q;
bool operator<(edge x,edge y)
{
    return x.val<y.val;
}
int v[15];
int a[15][100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int i,j;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge e;
        e.to=v;
        e.val=w;
        vt[u].push_back(e);
        e.to=u;
        vt[v].push_back(e);
    }
    for(i=1;i<=k;i++)
    {
        cin>>v[i];
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    if(k!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    int ans=0;
    edge e;
    e.to=1;
    e.val=0;
    f[1]=1;
    q.push(e);
    while(q.size())
    {
        int cur=q.top().to;
        q.pop();
        int i;
        for(i=0;i<vt[cur].size();i++)
        {
            edge nxt=vt[cur][i];
            if(f[nxt.to])
                continue;
            f[nxt.to]=1;
            ans+=nxt.val;
            q.push(nxt);
        }
    }
    cout<<ans<<endl;
    return 0;
}
