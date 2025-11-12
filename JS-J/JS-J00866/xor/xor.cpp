#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, k, ans;
int a[N], pr[N];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    bool pflg = 1;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), pr[i] = pr[i - 1] ^ a[i], pflg &= (a[i] <= 1);
    if (n <= 100 && !pflg)
    {
        for (int tt = 1; tt <= n; ++tt)
        {
            int l = tt, r = tt, cnt = 0;
            while (r <= n && l <= r)
            {
                bool flg = 0;
                for (int i = l; i <= r; ++i)
                {
                    if ((pr[r] ^ pr[i - 1]) == k)
                        {flg = 1; ++cnt, l = r + 1, r = l; break; };
                }
                if (!flg)
                    ++r;
            }
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
        return 0;
    }
    int l = 1, r = 1;
    while (r <= n && l <= r)
    {
        if ((pr[r] ^ pr[l - 1]) == k)
            ++ans, l = r + 1, r = l;
        else
            ++r;
    }
    printf("%d\n", ans);
    return 0;
}
