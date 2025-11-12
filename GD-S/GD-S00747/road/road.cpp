#include<cstdio>
#include<algorithm>
#include<vector>
const int N=2e4+1, K=11, M=2e6+1;
struct Road {
    int u, v, w;
};
std::vector<Road> r;
struct DSU {
    int fa[N], n;
    DSU(int _n) {
        n=_n;
        for(int i=1; i<=n; i++) {
            fa[i]=i;
        }
    }
    int find(int x) {
        return fa[x]!=x?fa[x]=find(fa[x]):x;
    }
    bool merge(int a, int b) {
        int x=find(a), y=find(b);
        if(x!=y) {
            fa[x]=y;
            return 1;
        }
        return 0;
    }
};
int n, m, k;
int c[K], a[K][N];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    DSU dsu(n+n);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        r.push_back({u,v,w});
    }
    std::sort(r.begin(), r.end(), [](const Road& a, const Road& b) {
        return a.w<b.w;
    });
    int cnt=0;
    long long W=0;
    for(int i=0; i<r.size(); i++) {
        int u=r[i].u, v=r[i].v, w=r[i].w;
        if(dsu.merge(u, v)) {
            W+=r[i].w;
            if(++cnt==n+k-1) break;
        }
    }
    if(k==0) return printf("%lld\n", W), 0;
    for(int i=1; i<=k; i++) {
        scanf("%d", c+i);
        for(int j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
            r.push_back({n+k,j,a[i][j]});
        }
    }
    std::sort(r.begin(), r.end(), [](const Road& a, const Road& b) {
        return a.w<b.w;
    });
    cnt=0;
    W=0;
    dsu=DSU(n+n);
    for(int i=0; i<r.size(); i++) {
        int u=r[i].u, v=r[i].v, w=r[i].w;
        if(dsu.merge(u, v)) {
            W+=r[i].w;
            if(++cnt==n+k-1) break;
        }
    }
    printf("%lld\n", W);
}