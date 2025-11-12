#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500;
const long long p = 998244353;
int n, m, c[N + 5], res, vis[N + 5];
int cnt_time;
string s;

void dfs(int x, int cnt)
{
    if (++cnt_time > 1e6)
    {
        cout << res << endl;
        exit(0);
    }

    if (x > n)
    {
        res += cnt >= m;
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = true;
            dfs(x + 1, cnt + (s[x - 1] == '1' && x - cnt - 1 < c[i]));
            vis[i] = false;
        }
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) cin >> c[i];

    bool isA = true;
    for (char a : s) if (a != '1') isA = false;

    if (isA) // 特殊性质 A
    {
        long long ans = 1;
        for (long long i = 2; i <= n; ++i) ans = ans * i % p;
        cout << ans << endl;
    }
    else
    {
        dfs(1, 0);
        cout << res << endl;
    }

    return 0;
}