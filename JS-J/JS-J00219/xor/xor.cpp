#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<utility>
#include<cstring>

typedef std::pair<int, int> pii;
#define l first
#define r second

constexpr int N = 5e5 + 5, V = 1 << 20;

int n, k, a[N], lst[V]; pii x[N];

// Difficulty: A < B < D < C.
// A: red, B: orange, C: green, D: yellow.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::memset(lst, -1, sizeof lst);

    std::freopen("xor.in", "r", stdin);
    std::freopen("xor.out", "w", stdout);

    std::cin >> n >> k; lst[0] = 0;
    int pfx = 0, l = 0; for(int i = 1; i <= n; ++i) {
        std::cin >> a[i]; pfx ^= a[i];
        if(~lst[pfx ^ k]) x[++l] = {lst[pfx ^ k] + 1, i};
        lst[pfx] = i;
    }
    std::sort(x + 1, x + l + 1, [&](const pii& a, const pii& b) { return a.r < b.r; });
    int maxr = -1, ans = 0;
    for(int i = 1; i <= l; ++i) {
        if(x[i].l > maxr) ++ans, maxr = std::max(maxr, x[i].r);
    }
    std::cout << ans << "\n";

    return 0;
}
