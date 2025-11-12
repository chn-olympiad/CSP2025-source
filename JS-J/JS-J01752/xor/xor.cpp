// AC!
// jiazhichen844 bless me
// DTL123 bless me
// xuanxuanni bless me
// throwAC bless me
// AutumnQ bless me
// chennie bless me
// Sving1024 bless me
// cmhcmh bless me
// Cubber/Aubber bless me
// Richard1211 bless me
// FlamingBlade bless me
// A_foolish_guy bless me
// jiangly bless me
// tourist bless me

#include<bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

namespace jiangly{
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1, 0);
    std::vector<int> pre(n + 1, 0);
    std::vector<std::vector<int> > buc(1 << 20);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        buc[pre[i]].emplace_back(i);
    }

    // for (const auto&x : pre) std::cerr << x << ' ';
    // std::cerr << '\n';
    std::vector<std::pair<int, int> > segments;
    for (int i = 1; i <= n; ++i) {
        int need = pre[i - 1] ^ k;
        if (std::lower_bound(buc[need].begin(), buc[need].end(), i) != buc[need].end())
            segments.emplace_back(i, *std::lower_bound(buc[need].begin(), buc[need].end(), i));
    }

    std::sort(segments.begin(), segments.end(), [](const std::pair<int, int> &x, const std::pair<int,int> &y) -> bool {
        return (x.second == y.second ?  x.first > y.first : x.second < y.second);
    });

    // for (const auto&x : segments) std::cerr << x.first << ' ' << x.second << '\n';
    int rgh = 0;
    int ans = 0;
    for (const auto&x : segments) {
        if (x.first > rgh) {
            ++ans;
            rgh = x.second;
        }
    }

    std::cout << ans << '\n';
}
}

int tests = 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    assert(freopen("xor.in", "r", stdin));
    assert(freopen("xor.out", "w", stdout));
    while (tests--) {
        jiangly::solve();
    }

    return 0;
}