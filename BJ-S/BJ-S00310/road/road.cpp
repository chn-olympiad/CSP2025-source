#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e4 + 50;
const int MAXM = 1e6 + 5;
const int MAXK = 15;
int n,m,k;
int c[MAXK],a[MAXK][MAXN];

struct Edge{
    int x,y,z;
    int id;
    Edge(){}
    Edge(int x,int y,int z,int id):x(x),y(y),z(z),id(id){}
};
Edge edges[MAXM];

inline bool operator < (Edge a,Edge b){
    return a.z < b.z;
}

namespace DSU{
    int fa[MAXN],sz[MAXN];

    void init(){
        for (int i = 1;i <= n + k;i ++)fa[i] = i,sz[i] = 1;
    }

    int find(int x){
        if (x == fa[x])return x;
        return fa[x] = find(fa[x]);
    }

    inline void merge(int x,int y){
        x = find(x),y = find(y);
        if (x == y)return;
        if (sz[x] < sz[y])swap(x,y);
        fa[y] = x;
        sz[x] += sz[y];
    }
}

int main(){
    #ifndef kevin
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i <= m;i ++){
        scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].z);
        edges[i].id = 0;
    }
    sort(edges + 1,edges + m + 1);

    int p = 0;
    DSU::init();
    for (int i = 1;i <= m;i ++){
        Edge it = edges[i];
        if (DSU::find(it.x) != DSU::find(it.y)){
            DSU::merge(it.x,it.y);
            edges[++p] = it;
        }
    }
    m = p;

    for (int j = 1;j <= k;j ++){
        scanf("%d",c + j);
        for (int i = 1;i <= n;i ++){
            scanf("%d",&a[j][i]);
            edges[++m] = Edge(i,j + n,a[j][i],j);
        }
    }
    sort(edges + 1,edges + m + 1);
    // printf("edges:\n");
    // for (int i = 1;i <= m;i ++)printf("%d %d %d %d\n",edges[i].x,edges[i].y,edges[i].z,edges[i].id);

    ll global = LONG_LONG_MAX;
    for (int S = 0;S < (1 << k);S ++){
        int pcnt = __builtin_popcount(S);
        ll ans = 0;
        for (int i = 1;i <= k;i ++)
            if (S >> (i - 1) & 1)
                ans += c[i];
            
        DSU::init();
        int cnt = 0;
        for (int i = 1;i <= m;i ++){
            Edge it = edges[i];
            if (it.id && !(S >> (it.id - 1) & 1))continue;
            if (DSU::find(it.x) != DSU::find(it.y)){
                // printf("%d %d %d %d\n",it.x,it.y,it.z,it.id);
                DSU::merge(it.x,it.y);
                ans += it.z;
                cnt ++;
                if (cnt == n + pcnt - 1)break;
                if (ans >= global)break;
            }
        }
        global = min(global,ans);
        // printf("S %d ans %lld\n",S,ans);
    }
    printf("%lld\n",global);
    return 0;
}