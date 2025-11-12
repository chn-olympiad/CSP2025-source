#include <algorithm>
#include <cctype>
#include <cstdio>
#include <utility>
#define MAXN 100003
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
            x = x * 10 + (c ^ 48), c = gc();
    }
#undef SIZ
#undef gc
}
using IO::rd;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, n, ans, psiz[3];
    pair<int, int> w0, w1, w2;
    static int arr[3][MAXN];
    rd(t);
    while (t--)
    {
        rd(n);
        ans = psiz[0] = psiz[1] = psiz[2] = 0;
        for (int i = 1; i <= n; ++i)
        {
            rd(w0.first), w0.second = 0;
            rd(w1.first), w1.second = 1;
            rd(w2.first), w2.second = 2;
            if (w0 < w1)
                swap(w0, w1);
            if (w1 < w2)
                swap(w1, w2);
            if (w0 < w1)
                swap(w0, w1);
            arr[w0.second][++psiz[w0.second]] = w0.first - w1.first;
            ans += w0.first;
        }
        for (int i = 0; i < 3; ++i)
        {
            if (psiz[i] > (n >> 1))
            {
                nth_element(arr[i] + 1, arr[i] + psiz[i] - (n >> 1), arr[i] + psiz[i] + 1);
                for (int j = 1; j <= psiz[i] - (n >> 1); ++j)
                    ans -= arr[i][j];
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
