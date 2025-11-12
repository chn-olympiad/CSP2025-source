#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, a[4][100005];
ll cnt[4], sum = 0;
ll ch[100005];
vector<ll> cost;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while (t--)
    {
        cnt[1] = cnt[2] = cnt[3] = sum = 0;
        cost.clear();
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            ll maxx = 0, maxp = 1;
            for (int j = 1; j <= 3; j++)
            {
                scanf("%lld", &a[j][i]);
                if (a[j][i] > maxx)
                {
                    maxx = a[j][i];
                    maxp = j;
                }
            }
            cnt[maxp]++;
            sum += maxx;
            ch[i] = maxp;
        }
        ll bad = 0;
        for (int i = 1; i <= 3; i++)
        {
            if (cnt[i] > n / 2)
                bad = i;
        }
        if (!bad) printf("%lld\n", sum);
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (ch[i] == bad)
                {
                    ll maxx = 0;
                    for (int j = 1; j <= 3; j++)
                        if (j != bad)
                            maxx = max(maxx, a[j][i]);
                    cost.push_back(a[ch[i]][i] - maxx);
                }
            }
            sort(cost.begin(), cost.end());
            ll need = (cnt[bad] - n / 2);
            for (int i = 0; i < need; i++)
                sum -= cost[i];
            printf("%lld\n", sum);
        }
    }
    return 0;
}
