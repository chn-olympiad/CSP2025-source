#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
typedef long long ll;
inline int read() {int x; return scanf("%d", &x), x;}
namespace solve
{
    const int N = 1e5;
    int a[N + 5][3];
    int cs[N + 5];
    int cnt[3];
    int val[N + 5];
    int main()
    {
        int n = read();
        for (int i = 1; i <= n; i ++ )
            for (int j = 0; j < 3; j ++ )
                a[i][j] = read();
        int res = 0;
        for (int i = 0; i < 3; i ++ ) cnt[i] = 0;
        for (int i = 1; i <= n; i ++ )
        {
            int max = 0;
            for (int j = 0; j < 3; j ++ ) max = std :: max(max, a[i][j]);
            res += max;
            for (int j = 0; j < 3; j ++ ) if (max == a[i][j]) {cnt[j] ++ ; cs[i] = j; break;}
        }
        int p = -1;
        for (int i = 0; i < 3; i ++ ) if (cnt[i] > n / 2) p = i;
        if (~p)
        {
            int idx = 0;
            for (int i = 1; i <= n; i ++ )
                if (cs[i] == p)
                {
                    int max = 0, semax = 0;
                    for (int j = 0; j < 3; j ++ ) if (j != p) semax = std :: max(semax, a[i][j]); else max = a[i][j];
                    val[ ++ idx] = max - semax;
                }
            std :: sort(val + 1, val + idx + 1);
            for (int i = 1; i <= cnt[p] - n / 2; i ++ ) res -= val[i];
        }
        printf("%d\n", res);
        return 0;
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
#endif
    int T = read();
    while (T -- ) solve :: main();
    return 0;
}