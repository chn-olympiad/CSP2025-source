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

namespace chennie{
void solve() {
    std::string s;
    std::cin >> s;
    std::vector<int> num;
    for (const auto&c : s) if(c >= '0' and c <= '9') num.emplace_back(c - '0');
    std::sort(num.rbegin(), num.rend());

    for (const auto&x : num) std::cout << x;
    std::cout << '\n';
}
}

int tests = 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    assert(freopen("number.in", "r", stdin));
    assert(freopen("number.out", "w", stdout));
    while (tests--) {
        chennie::solve();
    }

    return 0;
}