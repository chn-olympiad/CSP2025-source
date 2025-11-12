#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::sort;
//#define DEBUG
#define freopen(...)
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif // DEBUG
struct EDGE {
    int a, b, w;
    operator int() { return w; }
};
int main() {
    freopen("data.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    EDGE edges[m];
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        edges[i] = {a, b, w};
    }
    sort(edges, edges+m);
    int updCost[k];
    EDGE updEdge[k][n];
    for(int i=0; i<k; i++) {
        cin >> updCost[i];
        for(int j=0; j<n; j++) {
            int w;
            cin >> w;
            updEdge[i][j] = {j, i+n, w};
        }
        sort(&updEdge[i][0], &updEdge[i][n]);
    }
    long long ans = -1;
    for(int upd=0; upd<(1<<k); upd++) {
        long long cost = 0;
        int updCnt = 0;
        for(int i=0; i<k; i++) {
            debug("%c", upd&(1<<i) ? '#' : '-');
            if(upd & (1<<i)) {
                cost += updCost[i];
                updCnt++;
            }
        }
        debug(": \n");
        EDGE updeds[updCnt*n];
        updCnt = 0;
        for(int i=0; i<k; i++) {
            if(upd & (1<<i)) {
                for(int j=0; j<n; j++) {
                    updeds[updCnt*n+j] = updEdge[i][j];
                }
                updCnt++;
            }
        }
        sort(updeds, updeds + n*updCnt);
        for(int i=0; i<n*updCnt; i++) {
            const auto &e = updeds[i];
            debug("%d <-> %d: %d\n", e.a, e.b, e.w);
        } debug("\n");
        EDGE eds[m + updCnt*n];
        {
            int i=0, j=0, ind=0;
            while(i<m && j<n*updCnt) {
                const EDGE &e1 = edges[i];
                const EDGE &e2 = updeds[j];
                EDGE e; bool type;
                if(e1.w < e2.w) {
                    e= eds[ind] = e1;
                    i++;
                    type=0;
                } else {
                    e= eds[ind] = e2;
                    j++;
                    type = 1;
                }
                debug("eds[%02d]#%s(%d,%d): %d %d %d\n", ind, (type?"upd":"raw"), i,j, e.a, e.b, e.w);
                ind++;
            }
            while(i<m) eds[ind]=edges[i], ind++, i++;
            while(j<n*updCnt) eds[ind]=updeds[j], ind++, j++;
        }
        for(int i=0; i<m+updCnt*n; i++) {
            const auto &e = eds[i];
            debug("%d <-> %d: %d\n", e.a, e.b, e.w);
        }
        bool vis[n+updCnt];
        for(int i=0; i<n+updCnt; i++) { vis[i] = false; }
        int id = 0;
        for(int i=1; i<n+updCnt; i++) {
            while(vis[eds[id].a] && vis[eds[id].b]) id++;
            vis[eds[id].a] = vis[eds[id].b] = true;
            cost += eds[id].w;
        }
        debug("%d\n", cost);
        if(cost < ans || ans<0) ans=cost;
    }
    cout << ans << std::endl;
    return 0;
}
