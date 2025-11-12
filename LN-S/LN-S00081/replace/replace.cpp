#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second

using namespace std;

const int N = 5e5 + 50, p = 998244353;

int n, m, q;
map <pair <string, string>, vector <pair <int, int>>> st;

void init() {

}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        string x, y;
        cin >> x >> y;
        if (x == y) continue;
        int l = 0, r = 0, len = x.size();
        while (l < len && x[l] == y[l]) ++l;
        while (r < len && x[l + r] != y[l + r]) ++r;
        x = x.substr(l, r);
        y = y.substr(l, r);
        st[{x, y}].push_back({l, len - l - r});
    }
    for (int i = 1; i <= q; i++) {
        string x, y;
        cin >> x >> y;
        int l = 0, r = 0, len = x.size();
        while (l < len && x[l] == y[l]) ++l;
        while (r < len && x[l + r] != y[l + r]) ++r;
        x = x.substr(l, r);
        y = y.substr(l, r);
        int ans = 0;
        int mx1 = l, mx2 = len - l - r;
        if (st.count({x, y}) == 0)
            printf("0\n");
        else {
            for (auto i : st[{x, y}]) {
                if (i.fi <= mx1 && i.se <= mx2)
                    ++ans;
            }
            printf("%d\n", ans);
        }
    }
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    init();
    int t = 1;
    //scanf("%d", &t);
    while (t--) solve();
    return 0;
}
