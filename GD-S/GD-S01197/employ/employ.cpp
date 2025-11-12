#include <algorithm>
#include <cstdio>
#include <numeric>
#define MAXN 13
#define MOD 998244353
using namespace std;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    if (n < 12)
    {
        int tot0, a[MAXN], perm[MAXN];
        unsigned int ans = 0;
        char dif[MAXN];
        scanf("%s", dif);
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        iota(perm, perm + n, 0);
        do
        {
            tot0 = 0;
            for (int i = 0; i < n; ++i)
                if (tot0 >= a[perm[i]] || dif[i] == '0')
                    ++tot0;
            if (n - tot0 >= m)
                ++ans;
        } while (next_permutation(perm, perm + n));
        while (ans >= MOD)
            ans -= MOD;
        printf("%u", ans);
        return 0;
    }
    unsigned long long ans = 1;
    for (int i = 2; i <= n; ++i)
        ans = ans * i % MOD;
    printf("%llu", ans);
    return 0;
}
