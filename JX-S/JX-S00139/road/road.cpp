#include<bits/stdc++.h>
using namespace std;

int n, m, k, N;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;
const int maxk = 10 + 5;

struct node {
    int c, id;
    node(int _c = 0, int _id = 0) : c(_c), id(_id) {}
    friend bool operator < (node e1, node e2) {
        return e1.c < e2.c;
    }
    void In(int i) {
        scanf("%d", &c);
        id = i;
    }
} poi[maxk];

typedef long long ll;
struct Line {
    int u, v, w, op;
    Line(int _u = 0, int _v = 0, int _w = 0, int _op = 0) : u(_u), v(_v), w(_w), op(_op) {}
    void In() {
        scanf("%d%d%d", &u, &v, &w);
        op = 0;
    }
    friend bool operator < (Line e1, Line e2) {
        return e1.w < e2.w;
    }
} line[maxm + maxn * maxk];

int root[maxn];
int fid(int x) {return x ^ root[x] ? root[x] = fid(root[x]) : x;}
bool Merge(int u, int v) {
    u = fid(u), v = fid(v);
    if(u ^ v) {
        root[u] = v;
        return true;
    }
    return false;
}
void init() {
    for(int i = 1; i <= N; i ++) {
        root[i] = i;
    }
}

ll ans, pre, mst;
bool vis[maxk];
int tag[maxk];

#define lowbit(x) (x & (-x))

ll smakk() {
    for(int cur = 0; cur < (1 << k); cur ++) {
        mst = 0;
        for(int i = 1; i <= k; i ++) {
            if((cur >> (i - 1)) & 1) {
                vis[poi[i].id] = true;
                mst += poi[i].c;
            }
            else vis[poi[i].id] = false;
        }
        for(int j = 1; j <= k; j ++) tag[j] = 0;

        init();
        for(int j = 1, u, v, w, op; j <= m; j ++) {
            u = line[j].u;
            v = line[j].v;
            w = line[j].w;
            op = line[j].op;
            if(op && !vis[op]) continue;
            if(Merge(u, v)) {
                mst += w;
                if(op) tag[op] ++;
            }
        }
        for(int j = 1; j <= k; j ++) {
            if(vis[poi[j].id] && tag[poi[j].id] < 2) {
                mst -= poi[j].c;
            }
        }
        ans = min(ans, mst);
        //printf("cur:%d, pre:%lld, mst:%lld\n", cur, pre, mst);
    }
    return ans;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 1; i <= m; i ++) line[i].In();
    N = n + k;
    //init();
    ans = 0x3f3f3f3f3f3f3f3f;
    //bool gloria;
    for(int i = n + 1, cc, aa; i <= N; i ++) {
        poi[i - n].In(i - n);
        cc = poi[i - n].c;
        vis[i - n] = false;
        for(int j = 1; j <= n; j ++) {
            scanf("%d", &aa);
            line[++ m] = Line(i, j, aa, i - n);
        }
    }
    sort(line + 1, line + m + 1);
    sort(poi + 1, poi + k + 1);

    if(k <= 5) {
        printf("%lld\n", smakk());
        return 0;
    }

    pre = 0;
    for(int i = 1, c, id; i <= k; i ++) {
        init();
        c = poi[i].c;
        id = poi[i].id;
        pre += c;
        mst = pre;
        vis[id] = true;
        for(int j = 1; j <= k; j ++) {
            tag[j] = 0;
        }
        for(int j = 1, u, v, w, op; j <= m; j ++) {
            u = line[j].u;
            v = line[j].v;
            w = line[j].w;
            op = line[j].op;
            if(op && !vis[op]) continue;
            if(Merge(u, v)) {
                mst += w;
                if(op) tag[op] ++;
            }
        }
        for(int j = 1; j <= i; j ++) {
            if(tag[poi[j].id] < 2) {
                mst -= poi[j].c;
            }
        }
        ans = min(ans, mst);
        //printf("i:%d, pre:%lld, mst:%lld\n", i, pre, mst);
    }
    printf("%lld\n", ans);
    return 0;
}
