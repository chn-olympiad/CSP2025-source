#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

namespace OLD {

const int N = 1e5 + 5, inf = 1e18;

int a[N][4];

int cnt[4], ans;

int from[N];

struct Node {
    int val, idx, d, pre;
    bool operator < (const Node &rhs) const {
        return val < rhs.val;
    } 
};

priority_queue<Node> q[4][4], nq;   //  (to, from)

inline bool chk() {
    for (int i = 1; i <= 3; i++) {
        if (cnt[i] > n >> 1) return 1;
    }
    return 0;
}

inline bool change() {
    int mx = -inf;
    Node mxi = {0, 0, 0, 0}, mxj = {0, 0, 0, 0};
    for (int i = 1; i <= 3; i++) {
        for (int j = i + 1; j <= 3; j++) {
            while (!q[i][j].empty() && (from[q[i][j].top().idx] != j || q[i][j].top().pre != j)) q[i][j].pop();
            while (!q[j][i].empty() && (from[q[j][i].top().idx] != i || q[j][i].top().pre != i)) q[j][i].pop();
            if (q[i][j].empty() || q[j][i].empty()) continue;
            auto tp1 = (q[i][j].empty() ? (Node){0, 0, 0, 0} : q[i][j].top());
            auto tp2 = (q[j][i].empty() ? (Node){0, 0, 0, 0} : q[j][i].top());
            // printf("tp1:%lld %lld %lld %lld\n", tp1.val, tp1.idx, tp1.d, tp1.pre);
            // printf("tp2:%lld %lld %lld %lld\n", tp2.val, tp2.idx, tp2.d, tp2.pre);
            // if (tp1.val + tp2.val > mx && ((cnt[tp1.d] < n >> 1 && cnt[tp2.d] < n >> 1) || (tp1.d == tp2.pre && tp2.d == tp1.pre))) {
            if (tp1.val + tp2.val > mx && ((cnt[tp1.d] < n >> 1 || tp1.d == tp2.pre) && (cnt[tp2.d] < n >> 1 || tp2.d == tp1.pre))) {
                mx = tp1.val + tp2.val, mxi = tp1, mxj = tp2;
            }
            tp1 = (q[j][j].empty() ? (Node){0, 0, 0, 0} : q[j][j].top());
            tp2 = (q[j][i].empty() ? (Node){0, 0, 0, 0} : q[j][i].top());
            // printf("tp1:%lld %lld %lld %lld\n", tp1.val, tp1.idx, tp1.d, tp1.pre);
            // printf("tp2:%lld %lld %lld %lld\n", tp2.val, tp2.idx, tp2.d, tp2.pre);
            if (tp1.val + tp2.val > mx && ((cnt[tp1.d] < n >> 1 || tp1.d == tp2.pre) && (cnt[tp2.d] < n >> 1 || tp2.d == tp1.pre))) {
                mx = tp1.val + tp2.val, mxi = tp1, mxj = tp2;
            }
            tp1 = (q[i][j].empty() ? (Node){0, 0, 0, 0} : q[i][j].top());
            tp2 = (q[i][i].empty() ? (Node){0, 0, 0, 0} : q[i][i].top());
            // printf("tp1:%lld %lld %lld %lld\n", tp1.val, tp1.idx, tp1.d, tp1.pre);
            // printf("tp2:%lld %lld %lld %lld\n", tp2.val, tp2.idx, tp2.d, tp2.pre);
            if (tp1.val + tp2.val > mx && ((cnt[tp1.d] < n >> 1 || tp1.d == tp2.pre) && (cnt[tp2.d] < n >> 1 || tp2.d == tp1.pre))) {
                mx = tp1.val + tp2.val, mxi = tp1, mxj = tp2;
            }
        }
    }
    // cout << mx << endl;
    // printf("mxi:%lld %lld %lld %lld\n", mxi.val, mxi.idx, mxi.d, mxi.pre);
    // printf("mxj:%lld %lld %lld %lld\n", mxj.val, mxj.idx, mxj.d, mxj.pre);
    if (mxi.idx == 0 || mxj.idx == 0) return 0;
    if (mx > 0) {
        auto tp1 = mxi;
        auto tp2 = mxj;
        ans += tp1.val + tp2.val;
        for (int k = 1; k <= 3; k++) {
            q[k][tp2.d].push({a[tp2.idx][k] - a[tp2.idx][tp2.d], tp2.idx, k, tp2.d});
            q[k][tp2.d].push({a[tp1.idx][k] - a[tp1.idx][tp1.d], tp1.idx, k, tp1.d});
        }
        from[tp1.idx] = tp1.d, from[tp2.idx] = tp2.d;
        cnt[tp1.pre]--, cnt[tp1.d]++;
        cnt[tp2.pre]--, cnt[tp2.d]++;
        // printf("change: %lld %lld %lld %lld\n", tp1.pre, tp1.d, tp2.pre, tp2.d);
        return 1;
    }
    return 0;
}

void solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(from, 0, sizeof(from));
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            while (!q[i][j].empty()) q[i][j].pop();
    while (!nq.empty()) nq.pop();
    ans = 0;
    // scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            scanf("%lld", &a[i][j]);
            if (j == 1) {
                cnt[j]++, ans += a[i][j], from[i] = 1;
            } else {
                // q[j][1].push({a[i][j] - a[i][1], i, j, 1});
                nq.push({a[i][j] - a[i][1], i, j, 1});
            }
        }
    }
    
    while (chk() || nq.top().val > 0) {
        auto tp = nq.top();
        nq.pop();
        if (tp.pre != from[tp.idx]) continue;
        if (cnt[tp.d] >= n >> 1) continue;
        ans += tp.val;
        from[tp.idx] = tp.d, cnt[tp.pre]--, cnt[tp.d]++;
    }

    // for (int i = 1; i <= 3; i++) printf("%lld ", cnt[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            // if (j == from[i]) continue;
            q[j][from[i]].push({a[i][j] - a[i][from[i]], i, j, from[i]});
        } 
    }
    
    bool flag = 1;

    while (flag) {
        flag = change();
        // cout << /flag << endl;
    }  
    printf("%lld\n", ans);
    // for (int i = 1; i <= n; i++) {
    //     printf("%lld %lld\n", from[i], a[i][from[i]]);
    // }
    // for (int i = 1; i <= 3; i++) printf("%lld ", cnt[i]);
    // printf("\n");
}

} // namespace OLD

namespace BF {

const int N = 205, inf = 1e18;

int a[N][4];

int f[2][N][N], cur, lst;

void solve() {
    memset(f, 0, sizeof(f));
    lst = 0, cur = 1;
    // scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, n >> 1); j++) {
            for (int k = 0; k <= min(i, n >> 1); k++) {
                if (i - j - k > n >> 1) continue;
                if (j) f[cur][j][k] = max(f[cur][j][k], f[lst][j - 1][k] + a[i][1]);
                if (k) f[cur][j][k] = max(f[cur][j][k], f[lst][j][k - 1] + a[i][2]);
                if (i - j - k) f[cur][j][k] = max(f[cur][j][k], f[lst][j][k] + a[i][3]);
                if (i == n) ans = max(ans, f[cur][j][k]);
            }
        }
        swap(cur, lst);
    }
    printf("%lld\n", ans);
}

} // namespace BF

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        if (n <= 200) {
            BF::solve();
        } else {
            OLD::solve();
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}