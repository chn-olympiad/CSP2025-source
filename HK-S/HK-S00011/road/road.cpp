#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define debug(x) cerr << #x << ": " << x << endl
#define tree tree<pair<int, pair<int, int>>, null_type, less<pair<int, pair<int, int>>>, rb_tree_tag, tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;

const int MAXN = 2e4 + 7;
int a[MAXN][17], c[MAXN], fa[MAXN];
tree tr;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
    vector<pair<int, pair<int, int>>> qwq;
    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
        qwq.push_back(make_pair(w, make_pair(u, v)));
    }
    bool dam = true;
    for (int i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
        if (c[i] != 0) dam = false;
        bool lol = false;
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]);
            if (a[i][j] == 0) lol = true;
        }
        if (!lol) dam = false;
    }
    if (dam) {
        for (int i = 0; i < MAXN; i++) fa[i] = i;
        for (int i = 0; i < k; i++)
            for (int j = 1; j <= n; j++)
                qwq.push_back(make_pair(a[i + 1][j], make_pair(n + i + 1, j)));
        sort(qwq.begin(), qwq.end());
        int sum = 0;
        for (pair<int, pair<int, int>> i : qwq) {
            int u = i.second.first, v = i.second.second;
            if (find(u) == find(v)) continue;
            merge(u, v);
            sum += i.first;
        }
        cout << sum << '\n';
        return 0;
    }
    for (auto i : qwq) tr.insert(i);
    int ans = 1e18;
    for (int bit = 0; bit < (1ll << k); bit++) {
        int sum = 0;
        for (int i = 1; i <= n + k; i++) fa[i] = i;
        for (int i = 0; i < k; i++)
            if ((bit >> i) & 1) {
                sum += c[i + 1];
                for (int j = 1; j <= n; j++)
                    tr.insert(make_pair(a[i + 1][j], make_pair(n + i + 1, j)));
            }
        for (pair<int, pair<int, int>> i : tr) {
            int u = i.second.first, v = i.second.second;
            if (find(u) == find(v)) continue;
            merge(u, v);
            sum += i.first;
        }
        for (int i = 0; i < k; i++)
            if ((bit >> i) & 1) {
                for (int j = 1; j <= n; j++)
                    tr.erase(make_pair(a[i + 1][j], make_pair(n + i + 1, j)));
            }
        ans = min(ans, sum);
        if (clock() / 1.0 / CLOCKS_PER_SEC > 0.9) break;
    }
    printf("%lld\n", ans);
}
