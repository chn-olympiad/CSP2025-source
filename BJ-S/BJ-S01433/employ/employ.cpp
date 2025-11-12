#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n,m,a[505],ans,flag[505],b[505];
void dfs(ll step,ll cnt,ll fail)
{
    if (step > n)
    {
        if (cnt >= m) ans++;
        ans %= mod;
        return;
    }
    for (ll i = 1;i <= n;i++)
    {
        if (!flag[i])
        {
            flag[i] = 1;
            if (a[step] == 0 || fail >= b[i]) dfs(step+1,cnt,fail+1);
            else dfs(step+1,cnt+1,fail);
            flag[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    string s;
    cin >> s;
    bool flag1 = 1,flag2 = 1;
    for (ll i = 0;i < n;i++)
    {
        a[i+1] = s[i] - '0';
        if (!a[i+1]) flag1 = 0;
        if (a[i+1]) flag2 = 0;
    }
    for (ll i = 1;i <= n;i++) cin >> b[i];
    if (n <= 10)
    {
        dfs(1,0,0);
        cout << ans;
        return 0;
    }
    if (flag1)
    {
        ans = 1;
        for (ll i = 1;i <= n;i++)
        {
            ans *= i;
            ans %= mod;
        }
        cout << ans;
        return 0;
    }
    if (m == 1)
    {
        if (!flag2) ans = 1;
        for (ll i = 1;i <= n;i++)
        {
            ans *= i;
            ans %= mod;
        }
        cout << ans;
        return 0;
    }
    if (m == n)
    {
        if (flag1)
        {
            ans = 1;
            for (ll i = 1;i <= n;i++)
            {
                ans *= i;
                ans %= mod;
            }
            cout << ans;
        }
        else cout << 0;
        return 0;
    }
    else cout << 0;
    return 0;
}
