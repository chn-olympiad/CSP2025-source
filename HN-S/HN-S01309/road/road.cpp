#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 11, M = 1e4 + 4;
array<int, 3>d[N], dd[N];
int g[11][M], p[N], c[N], mk[N], n;
int find(int node) {
    return node == p[node] ? node : p[node] = find(p[node]);
}
ll calc(int need, int m1, int m2) {
    ll sum = 0;
    iota(p, p + n + 11, 0);
    need--;
    int pos = 0;
    for (int i = 0; i < m1;) {
        auto[c, a, b] = dd[i];
        auto[c1, a1, b1] = d[pos];
        if (c1 < c) {
            pos++;
            if (!mk[a1])continue;
            a1 = find(a1 + n + 1), b1 = find(b1);
            if (a1 == b1)continue;
            p[a1] = b1;
            sum += c1;
            if (--need == 0)break;
            continue;
        }
        a = find(a), b = find(b);
        i++;
        if (a == b)continue;
        p[a] = b;
        sum += c;
        if (--need == 0)break;
    }
    return sum;
}
void solve() {
    int m, k, a, b, cc, tot = 0;
    cin >> n >> m >> k, iota(p, p + n + 1, 0);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> cc;
        d[i] = {cc, a, b};
    }
    sort(d, d + m);
    int need = n - 1;
    for (int i = 0; i < m; i++) {
        auto[c, a, b] = d[i];
        a = find(a), b = find(b);
        if (a == b)continue;
        p[a] = b;
        dd[tot++] = d[i];
        ans += c;
        if (--need == 0)break;
    }
    int tot2 = 0;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            d[tot2++] = {x, i, j};
        }
    }
    sort(d, d + tot2);
    int up = 1 << k, n1 = n + 1;
    for (int i = 0; i < up; i++) {
        ll sum = 0;
        int tot1 = tot, b = 0;
        for (int j = 0; j < k; j++)
            if (i >> j & 1) {
                ++b;
                sum += c[j];
                mk[j] = 1;
            } else mk[j] = 0;
        ans = min(ans, sum + calc(n + b, tot1, tot2));
    }
    cout << ans << '\n';
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
