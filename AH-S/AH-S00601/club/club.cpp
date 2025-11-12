#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

const int N = 1e5 + 10;

int n;
LL a[N], b[N], c[N];
PLI x[N], y[N], z[N];
LL t[N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);

    while (T -- )
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);

        int cntx = 0, cnty = 0, cntz = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (a[i] >= b[i] && a[i] >= c[i]) x[ ++ cntx] = {a[i], i};
            else if (b[i] >= a[i] && b[i] >= c[i]) y[ ++ cnty] = {b[i], i};
            else z[ ++ cntz] = {c[i], i};
        }

        int cntt = 0;
        if (cntx > n / 2)
        {
            for (int i = 1; i <= cntx; i ++ )
            {
                int v = x[i].second;
                if (b[v] >= c[v]) t[ ++ cntt] = b[v] - a[v];
                else t[ ++ cntt] = c[v] - a[v];
            }

            sort(t + 1, t + 1 + cntt, greater<LL>());

            int len = cntx - n / 2;
            for (int i = 1; i <= len; i ++ )
                x[ ++ cntx] = {t[i], cntx};
        }
        else if (cnty > n / 2)
        {
            for (int i = 1; i <= cnty; i ++ )
            {
                int v = y[i].second;
                if (a[v] >= c[v]) t[ ++ cntt] = a[v] - b[v];
                else t[ ++ cntt] = c[v] - b[v];
            }

            sort(t + 1, t + 1 + cntt, greater<LL>());

            int len = cnty - n / 2;
            for (int i = 1; i <= len; i ++ )
                y[ ++ cnty] = {t[i], cnty};
        }
        else if (cntz > n / 2)
        {
            for (int i = 1; i <= cntz; i ++ )
            {
                int v = z[i].second;
                if (a[v] >= b[v]) t[ ++ cntt] = a[v] - c[v];
                else t[ ++ cntt] = b[v] - c[v];
            }

            sort(t + 1, t + 1 + cntt, greater<LL>());

            int len = cntz - n / 2;
            for (int i = 1; i <= len; i ++ )
               z[ ++ cntz] = {t[i], cntz};
        }

        LL res = 0;
        for (int i = 1; i <= cntx; i ++ ) res += x[i].first;
        for (int i = 1; i <= cnty; i ++ ) res += y[i].first;
        for (int i = 1; i <= cntz; i ++ ) res += z[i].first;

        printf("%lld\n", res);
    }

    return 0;
}
