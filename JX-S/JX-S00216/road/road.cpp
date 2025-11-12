#include <bits/stdc++.h>
using namespace std;

int n, m, k, uu[1000005], vv[1000005], id[1000005];
long long ww[1000005];
pair<long long, int> pli[1000005];
int fa[10050];
bool vis0[1000005], vis[15];
int sz, U[110005], V[110005], s;
long long c[15], W[110005], ans;

int gtf(int u) {
    if (fa[u] == u) return u;
    return fa[u] = gtf(fa[u]);
}

bool merge(int u, int v) {
    u = gtf(u);
    v = gtf(v);
    if (u == v) return 0;
    fa[u] = v;
    return 1;
}

void init() {
    for (int i = 1; i <= n; i++) fa[i] = i;
    int cnt = 0;
    for (int i = 1; i <= m && cnt < n; i++) {
        int j = pli[i].second;
        int u = uu[j], v = vv[j];
        if(merge(u, v)) {
            vis0[i] = 1;
            cnt++;
            ans += pli[i].first;
        }
    }
}

long long krus() {
    long long ret = 0;
    for (int i = 1; i <= n + k; i++) fa[i] = i;
    int cnt = 0;
    for (int i = 1; i <= sz && cnt < n + s; i++) {
        int j = pli[i].second;
        if (id[j] != 0 && !vis[id[j]]) continue;
        int u = U[j], v = V[j];
        if(merge(u, v)) {
            cnt++;
            ret += pli[i].first;
        }
    }
    return ret;
}

void dfs(int step, long long sum) {
    if (step > k) {
        ans = min(ans, sum + krus());
        return;
    }
    vis[step] = 0;
    dfs(step + 1, sum);
    vis[step] = 1;
    s++;
    dfs(step + 1, sum + c[step]);
    s--;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> uu[i] >> vv[i] >> ww[i];
        pli[i] = make_pair(ww[i], i);
    }
    sort(pli + 1, pli + m + 1);
    init();
    for (int i = 1; i <= m; i++) {
        if (vis0[i]) {
            int j = pli[i].second;
            sz++;
            U[sz] = uu[j];
            V[sz] = vv[j];
            pli[sz] = make_pair(ww[j], sz);
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            sz++;
            cin >> ww[j];
            U[sz] = n + i;
            V[sz] = j;
            id[sz] = i;
            pli[sz] = make_pair(ww[j], sz);
        }
    }
    sort(pli + 1, pli + sz + 1);
    dfs(1, 0);
    cout << ans;
    return 0;
}
