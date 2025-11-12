#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;

constexpr int N=1e4+10;
constexpr int M=1e6+10;
constexpr int K=20;

struct Edge{
    int u,v,w;

    friend bool operator<(const Edge &lhs, const Edge &rhs){
        return lhs.w<rhs.w;
    }
};

int parent[N];


int find(const int &point){
    if(!parent[point]) return parent[point] = point;
    int p=point;
    while(parent[p] != p)p = parent[p];
    return /*parent[point] = */p;
}

void merge(int lhs, int rhs){
    // if(!parent[lhs] && !parent[rhs]){
    //     parent[rhs] = parent[lhs] = lhs;
    // } else if(parent[lhs] && !parent[rhs]){
    //     parent[rhs] = parent[lhs];
    // }
    // else{
    //     parent[lhs] = parent[rhs];
    // }
    // find(lhs);
    // find(rhs);
    // printf("lhs=%d rhs=%d find(lhs)=%d find(rhs)=%d parent[lhs]=%d parent[rhs]=%d\n",
    //     lhs,rhs,find(lhs),find(rhs),parent[lhs],parent[rhs]
    // );
    find(lhs);
    if(find(rhs) == rhs) parent[rhs] = find(lhs);
    else parent[lhs] = find(rhs);
}

int n,m,k;

int g[N][N];
vector<Edge> edges;
int c[K];
int a[K][N];

int main(){
    (void)freopen("road.in","r",stdin);
    (void)freopen("road.out","w",stdout);
    // (void)freopen("/dev/null","w",stderr);

    cin>>n>>m>>k;

    memset(a, 0x3f, sizeof(a));

    // printf("a[k][n]=%d\n",a[k][n]);

    // edges.resize(m);
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        if(!g[u][v])g[u][v]=w;
        else g[u][v] = min(g[u][v], w);

        g[v][u] = g[u][v];

        // cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    bool s1=true;
    for(int i=1;i<=k;++i){
        cin>>c[i];
        if(c[i])s1=false;
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }

    if(s1){
        for(int l=1;l<=k;++l){
            for(int u=1;u+1<=n;++u){
                for(int v=u+1;v<=n;++v){
                    if(!g[u][v])g[u][v]=0x3f3f3f3f;
                    // if(u == 1 && v == 3){
                    //     fprintf(stderr, "a[%d][1]+a[%d][3]: %d\n",l,l,a[l][u]+a[l][v]);
                    // }
                    g[u][v] = min(g[u][v], a[l][u]+a[l][v]);
                }
            }
        }
    }

    for(int u=1;u+1<=n;++u){
        for(int v=u+1;v<=n;++v){
            // printf("g[%d][%d]=%d\n",u,v,g[u][v]);
            if(!g[u][v])continue;
            edges.push_back({u,v,g[u][v]});
            // fprintf(stderr,"%d -> %d: %d\n",u,v,g[u][v]);
        }
    }

    sort(edges.begin(), edges.end());

    // for(auto e:edges){
        // cout<<e.u<<' '<<e.v<<' '<<e.w<<'\n';
    // }


    vector<Edge> newEdges;
    for(int i=0;i<edges.size();++i){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if(find(u) != find(v)){
            merge(u,v);
            // fprintf(stderr, "merged: %d %d, %d %d",u,v,find(u),find(v));
            // for(int o=1;o<=n;++o)cerr<<parent[o]<<' ';
            // cerr<<'\n';
            newEdges.emplace_back(edges[i]);
        }
    }
    uint64_t sum=0;
    for(const auto&e:newEdges){
        sum+=e.w;
        // cerr<<e.u<<' '<<e.v<<' '<<e.w<<'\n';

    }
    // fprintf(stderr, "cnt=%d sum=%llu\n",newEdges.size(), sum);
    cout<<sum<<'\n';

    fclose(stdin);
    fclose(stdout);
    return 0;
}