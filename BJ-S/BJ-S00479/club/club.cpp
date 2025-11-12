#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
    int val, id, group;
    node(int v, int i, int g) : val(v), id(i), group(g) {}
    bool operator< (const node &r) const {
        if (val == r.val) return id < r.id;
        return val < r.val;
    }
};
priority_queue<node> pq;
int a[maxn][5], cnt[5];
bool vis[maxn];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            pq.emplace(a[i][1], i, 1);
            pq.emplace(a[i][2], i, 2);
            pq.emplace(a[i][3], i, 3);
        }
        int ans = 0;
        while (!pq.empty()) {
            node top = pq.top();
            pq.pop();
            if (vis[top.id] || cnt[top.group] + 1 > n / 2) continue;
            cnt[top.group]++;
            vis[top.id] = true;
            ans += top.val;
        }
        printf("%d\n", ans);
    }
    return 0;
}
