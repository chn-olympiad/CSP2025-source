#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

namespace IO
{
#define SIZ (1 << 18)
    char ibuf[SIZ], *p1 = nullptr, *p2 = nullptr;
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZ, stdin), p1 == p2) ? EOF : *p1++)
    void rd(int &x)
    {
        x = 0;
        char c = gc();
        while (!isdigit(c))
            c = gc();
        while (isdigit(c))
            x = (x * 10) + (c ^ 48), c = gc();
    }
#undef SIZ
#undef gc
}
using IO::rd;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, x, d = 0, las = 0, ans = 0;
    static int dp[1 << 20 | 3];
    fill(dp + 1, dp + (1 << 20 | 3), -0x3f3f3f3f);
    rd(n), rd(k);
    while (n--)
    {
        rd(x), d ^= x;
        ans = max(ans, las = dp[d] = max({dp[d], dp[d ^ k] + 1, las}));
    }
    printf("%d", ans);
    return 0;
}
