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

namespace Cubber{
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n * m + 1);
    for (int i = 1; i <= n * m; ++i) std::cin >> a[i];
    int num = a[1];
    std::sort(a.begin() + 1, a.end(), std::greater<>());
    // for (const auto&x : a) std::cerr << x << ' ';
    int pos = 0;
    for (int i = 1; i <= n * m; ++i) {
        if (a[i] == num) {
            pos = i;
            break;
        }
    }

    std::vector<std::vector<int> > ord(n + 2, std::vector<int>(m + 2, 0));
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) ord[j][i] = ++cnt;
        ++i;
        for (int j = n; j >= 1; --j) ord[j][i] = ++cnt;
    }

    // std::cerr << pos << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // std::cerr << ord[i][j] << ' ';
            if (ord[i][j] == pos) {
                std::cout << j << ' ' << i << '\n';
                return ;
            }
        }
        // std::cerr << '\n';
    }
}
}

int tests = 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    assert(freopen("seat.in", "r", stdin));
    assert(freopen("seat.out", "w", stdout));
    while (tests--) {
        Cubber::solve();
    }

    return 0;
}