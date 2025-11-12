#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;
const i64 MAXN = 1e6 + 10;
struct node_t {
    i64 v, id;
    bool operator > (const node_t& o) const {
        if (v == o.v) return id < o.id;
        return v > o.v;
    }
} br[MAXN][3];
i64 n;
std::vector<i64> pos[3];

bool check(void) {
    for (i64 i = 0; i < 3; ++i) {
        if ((i64) pos[i].size() > n / 2) return false;
    }
    return true;
}

void solve(void) {
    for (i64 i = 0 ; i < 3; ++i) {
        pos[i].clear();
    }
    std::cin >> n;
    i64 ans = 0;
    for (i64 i = 1; i <= n; ++i) {
        for (i64 j = 0; j < 3; ++j) {
            std::cin >> br[i][j].v;
            br[i][j].id = j;
        }
        std::sort(br[i], br[i] + 3, std::greater<node_t>());
        pos[br[i][0].id].emplace_back(i);
        ans += br[i][0].v;
    }
    if (check()) {
        std::cout << ans << '\n';
        return;
    }
    i64 id = 0;
    for (i64 i = 0; i < 3; ++i) {
        if ((i64) pos[i].size() > n / 2) {
            id = i;
            break;
        }
    }
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> que;
    for (i64 x : pos[id]) {
        que.emplace(br[x][0].v - br[x][1].v);
    }
    while ((i64) que.size() > n / 2) {
        ans -= que.top();
        que.pop();
    }
    std::cout << ans << '\n';
}

int main() {
    IG = freopen("club.in", "r", stdin);
    IG = freopen("club.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    i64 t = 0;
    std::cin >> t;
    while (t--) solve();

    return 0;
}
