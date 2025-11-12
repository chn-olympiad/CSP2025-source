#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;

const int MAX_N = 1e4+15, MAX_M = 1e6+5, MAX_2_K = (1<<10)+5;

int n, m, k, c[15], a[15][MAX_N];

struct Road_t {
    int u, v, w;

    Road_t () {
        u = v = w = 0;
    }

    Road_t (int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    friend bool operator < (const Road_t &x, const Road_t &y) {
        return x.w > y.w;
    }
};


Road_t r[MAX_M], mst[MAX_N][MAX_2_K];
LL ans;

namespace my_MST {
    int mst_cnt, fa[MAX_N], siz[MAX_N];
    priority_queue<Road_t> q;

    int find_fa (int x) {
        if(x == fa[x]) return x;
        fa[x] = find_fa(fa[x]);
        return fa[x];
    }

    void unions (int x, int y) {
        x = find_fa(x);
        y = find_fa(y);
        if(x != y) {
            if(siz[x] > siz[y]) swap(x, y);
            fa[x] = y;
            siz[y] += siz[x];
        }
    }

    void run () {
        for(int i = 1; i <= n; i ++) {
            fa[i] = i;
            siz[i] = 1;
        }
        for(int i = 1; i <= m; i ++) {
            q.push(r[i]);
        }
        mst_cnt = 0;
        while(!q.empty()) {
            Road_t x = q.top();
            q.pop();
            if(mst_cnt == n-1) continue;
            if(find_fa(x.u) != find_fa(x.v)) {
                ++ mst_cnt;
                mst[mst_cnt][0] = x;
                unions(x.u, x.v);
                ans += x.w;
            }
        }
    }
}

namespace t2_try_1 {

    int fa[MAX_N], siz[MAX_N];

    inline void init (int n) {
        for(int i = 1; i <= n; i ++) {
            fa[i] = i;
            siz[i] = 1;
        }
    }

    int find_fa (int x) {
        if(x == fa[x]) return x;
        fa[x] = find_fa(fa[x]);
        return fa[x];
    }

    inline void unions (int x, int y) {
        x = find_fa(x);
        y = find_fa(y);
        if(x != y) {
            if(siz[x] > siz[y]) swap(x, y);
            fa[x] = y;
            siz[y] += x;
        }
    }

    inline int low_bit (int x) {
        return x & (-x);
    }

    void run () {
        LL lis_ans = 0;
        int now = 0, cnt = 0, now_siz;
        priority_queue<Road_t> q;
        for(int s = 1; s < (1<<k); s ++) {
            lis_ans = 0;
            now = cnt = now_siz = 0;
            init(n+k);
            for(int j = 1; j <= k; j ++) {
                if(s & (1<<(j-1))) {
                    lis_ans += c[j];
                    ++ now_siz;
                    if(now == 0) {
                        now = j;
                    }
                }
            }
            int lst_s = s ^ (1<<(now-1));
            for(int i = 1; i <= n; i ++) {
                q.push(Road_t(n+now, i, a[now][i]));
            }
            for(int i = 1; i <= n+now_siz-2; i ++) {
                q.push(mst[i][lst_s]);
            }
            while(!q.empty() && cnt < n+now_siz-1) {
                Road_t x = q.top();
                q.pop();
                if(find_fa(x.u) != find_fa(x.v)) {
                    ++ cnt;
                    mst[cnt][s] = x;
                    lis_ans += x.w;
                    unions(x.u, x.v);
                }
            }
            ans = min(ans, lis_ans);
            while(!q.empty()) q.pop();
        }
        printf("%lld\n",ans);
    }
}

// my program has a big problem???
// O mlogm+n*2^k*logn bu neng guo qu
// shi ben di ji zi tai man le
// hai shi stl tai man le

int main () {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //freopen("road.in","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    ans = 0;
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
    }
    for(int i = 1; i <= k; i ++) {
        scanf("%d",&c[i]);
        for(int j = 1; j <= n; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    my_MST::run();
    if(k == 0) {
        printf("%lld\n",ans);
        return 0;
    }
    t2_try_1::run();
    return 0;
}
