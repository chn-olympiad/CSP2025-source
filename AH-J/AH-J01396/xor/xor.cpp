#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6 + 55;
int n, k, a[N], sum[N];
vector<int> v[N];
struct node { int l, r; } w[N];
bool cmp(node n1, node n2) {
    if (n1.r == n2.r) return n1.l < n2.l;
    return n1.r < n2.r;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum[i] = (sum[i - 1] ^ a[i]);
        v[sum[i]].push_back(i);
    }
    int cnt = 0;
    for (int i = 0;i <= n;i++) {
        int u = (sum[i] ^ k);
        int l = 0, r = v[u].size() - 1, s = -1, t = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[u][m] < i) s = m, l = m + 1;
            else r = m - 1;
        }
        l = 0, r = v[u].size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[u][m] > i) t = m, r = m - 1;
            else l = m + 1;
        }
        if (s != -1) w[++cnt] = {v[u][s] + 1, i};
        if (t != -1) w[++cnt] = {i + 1, v[u][t]};
    }
    sort(w + 1, w + 1 + cnt, cmp);
    int p = 2, lst = w[1].r, ans = 1;
    while (p <= cnt) {
        while (p <= cnt && lst >= w[p].l) p++;
        if (p <= cnt) lst = w[p].r, ans++, p++;
    }
    cout << ans;
    return 0;
}
