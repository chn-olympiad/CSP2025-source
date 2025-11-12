#include <algorithm>
#include <cstdio>
#include <numeric>
constexpr int MaxN = 5e2 + 5;
constexpr long long Mod = 998'244'353;
int n, m;
int p[MaxN];
int f[MaxN];
char s[MaxN];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    if (n <= 10)
    {
        int answer = 0;
        std::iota(f + 1, f + 1 + n, 1);
        for (;;)
        {
            int suc = 0;
            int fail = 0;
            for (int i = 1; i <= n; i++)
            {
                if (fail >= p[f[i]])
                {
                    fail++;
                    continue;
                }
                if (s[i] == '1')
                {
                    suc++;
                }
                else
                {
                    fail++;
                }
            }
            if (suc >= m)
            {
                answer++;
            }
            if (!std::next_permutation(f + 1, f + 1 + n))
            {
                break;
            }
        }
        printf("%d\n", answer);
        return 0;
    }
    return 0;
}
