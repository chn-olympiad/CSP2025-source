#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAXN = 5e3 + 5;
const ll MOD = 998244353;

int arr[MAXN];
int n;

bool check1()
{
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] != 1) return false;
    }

    return true;
}

ll C(int n, int m)
{
    ll tot = 1;

    for (ll i = m + 1; i <= n; ++i)
    {
        tot = tot % MOD * i % MOD;
    }

    for (ll i = 1; i <= n - m; ++i)
    {
        tot /= i;
    }

    return tot % MOD;
}

ll ans;

void dfs(int u, int tot, int MaxL, int S)
{
    if (u > n) 
    {
        if (tot >= 3 && MaxL * 2 < S)
            ans = (ans + 1) % MOD;
        return ;
    }

    dfs(u + 1, tot, MaxL, S);
    dfs(u + 1, tot + 1, arr[u], S + arr[u]);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    if (n <= 20)
    {
        dfs(1, 0, 0, 0);
        cout << ans % MOD << '\n';
        return 0;
    }

    if (check1())
    {
        for (int i = 3; i <= n; ++i)
        {
            ans = (ans % MOD + C(n, i) % MOD) % MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}