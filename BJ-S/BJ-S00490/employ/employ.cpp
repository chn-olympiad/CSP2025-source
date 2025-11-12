#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, m, cnt = 0;
string s;
ll c[505];
ll p[505];
bool us[505];
ll nx[505], pv[505];
ll ans = 0;
bool calc()
{
    //printf("TRYING ");
    //for (int i = 1; i <= n; i++)
    //    printf("%lld ", c[p[i]]);
    ll failed = 0;
    for (int i = 1; i <= n; i++)
    {
        if (failed >= c[p[i]])
            failed++;
        else
            if (s[i - 1] == '0')
                failed++;
        if (n - failed < m) return 0;
    }
    //if (n - failed >= m) printf("OK %lld >= %lld\n", n - failed, m);
    //else printf("FAIL\n");
    return n - failed >= m;
}
void dfs(ll now)
{
    if (now == n + 1)
    {
        if (calc())
            ans++;
        return ;
    }
    for (int i = nx[0]; i <= n; i = nx[i])
    {
        ll tmp1 = nx[pv[i]], tmp2 = pv[nx[i]];
        nx[pv[i]] = nx[i];
        pv[nx[i]] = pv[i];
        p[now] = i;
        dfs(now + 1);
        nx[pv[i]] = tmp1;
        pv[nx[i]] = tmp2;
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            cnt++;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &c[i]);
    if (n < m || cnt < m)
    {
        printf("0\n");
        return 0;
    }
    if (cnt == n)
    {
        ll ans = 1;
        for (int i = 1; i <= n; i++)
            ans = ans * i % mod;
        printf("%lld\n", ans);
        return 0;
    }
    for (int i = 0; i <= n + 1; i++)
        us[i] = 0, nx[i] = i + 1, pv[i] = i - 1;
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}
