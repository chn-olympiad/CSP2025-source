#include <bits/stdc++.h>

using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr u64 N = 100'000;

i64 weight[N][3];

void solve() {
    u32 n;
    cin >> n;
    for (u32 i = 0; i < n; i++) for (auto &k : weight[i]) cin >> k;
    array<multiset<array<i64, 4>>, 3> Ss;
    auto add = [&](u32 id, u32 p, u32 vis) {
        vis = vis | (1 << p);
        int f = -1;
        i64 q = numeric_limits<i64>::max();
        for (u32 tgt : {0, 1, 2}) if ((~vis >> tgt) & 1) if (weight[id][p] - weight[id][tgt] < q) f = tgt, q = weight[id][p] - weight[id][tgt];
        if (f != -1) Ss[p].insert({q, f, vis, id});
    };
    i64 ans = 0;
    for (u32 i = 0; i < n; i++) {
        u32 p = max_element(weight[i], weight[i] + 3) - weight[i];
        add(i, p, 0), ans += weight[i][p];
    }
    auto check = [&]() {
        return Ss[0].size() <= n / 2 && Ss[1].size() <= n / 2 && Ss[2].size() <= n / 2;
    };
    for (u32 p : {0, 1, 2}) {
        for (auto it = Ss[p].begin(); Ss[p].size() > n / 2 && it != Ss[p].end(); ) {
            if ((*it)[2] == 7) {
                it++;
                continue;
            }
            ans -= (*it)[0];
            add((*it)[3], (*it)[1], (*it)[2]);
            it = Ss[p].erase(it);
        }
    }
    cout << ans << "\n";
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    u32 T;
    for (cin >> T; T; T--) solve();
}

/**
 * 15:18, ~0.29 s, 100.
 */