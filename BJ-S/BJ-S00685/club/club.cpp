#include <cstdio>
#include <cstdint>
#include <cstring>
#include <array>
#include <vector>
#include <tuple>
#include <algorithm>

#define wzc(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

const int N = 1e5 + 8;

int a[N][4];
int cnt[3], d[N];

int main()
{
    wzc("club");
    int q; scanf("%d", &q);
    while (q--)
    {
        int n; scanf("%d", &n);
        memset(cnt, 0, 3 * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            int x, y, z; scanf("%d %d %d", &x, &y, &z);
            a[i][0] = x; a[i][1] = y; a[i][2] = z;
            int m = std::max({x, y, z});
            if (m == x) a[i][3] = 0;
            else if (m == y) a[i][3] = 1;
            else a[i][3] = 2;
            cnt[a[i][3]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += std::max({a[i][0], a[i][1], a[i][2]});
        int k = std::max({cnt[0], cnt[1], cnt[2]});
        if (k <= n / 2)
        {
            printf("%d\n", ans);
            continue;
        }
        int j = -1, dcnt = 0;
        if (cnt[0] > n / 2) j = 0;
        else if (cnt[1] > n / 2) j = 1;
        else j = 2;
        for (int i = 0; i < n; i++)
            if (a[i][3] == j)
                d[dcnt++] = a[i][j] - std::max(a[i][(j + 1) % 3], a[i][(j + 2) % 3]);
        std::sort(d, d + dcnt);
        for (int i = 0; i < k - n / 2; i++)
            ans -= d[i];
        printf("%d\n", ans);
    }
}