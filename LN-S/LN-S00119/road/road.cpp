#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u,v,c;
    Edge(int u, int v, int c) : u(u), v(v), c(c){}
};

class UF{
private:
    vector<int>p, r;
public:
    UF (int n){
        p.resize(n);
        r.resize(n, 0);
        for(int i=0;i<n;i++)p[i]=i;
    }
    int find(int x)
    {
        if(p[x]!=x)p[x]=find(p[x]);
        return p[x];
    }
    bool unite(int x, int y){
        int rx=find(x),ry=find(y);
        if(rx==ry)return false;
        if(r[rx]<r[ry])p[rx]=ry;
        else if(r[ry]<r[rx])p[ry]=rx;
        else p[ry]=rx,r[rx]++;
        return true;
    }
};

int ka(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
            return a.c<b.c;
    });
    UF uf(n);
    int cost=0,cnt=0;
    for(const auto & e : edges)
    {
        if(uf.unite(e.u, e.v))
        {
            cost+=e.c;
            cnt++;
            if(cnt==n-1)break;
        }
    }
    return cost;
}


int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<Edge>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        edges.push_back(Edge(u-1, v-1, c));
    }
    int ans=ka(n, edges);
    for(int i=0;i<k;i++)
    {
        int vc;
        cin>>vc;
        vector<int> cc(n);
        for(int j=0;j<n;j++)cin>>cc[j];
        vector<Edge> ne=edges;
        for(int j=0;j<n;j++)ne.push_back(Edge(n, j, cc[j]));
        int cost=ka(n+1, ne)+vc;
        ans=min(ans, cost);
    }
    cout<<ans;
    return 0;
}
