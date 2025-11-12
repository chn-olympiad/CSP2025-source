#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAXN 100005

using ll = long long;

int n;

ll a[MAXN][3];
ll res = 0;

priority_queue<ll> q[3];

void solve()
{
    cin >> n;
    res = 0;
    for (int i = 0; i < 3; i++)
    {
        priority_queue<ll>().swap(q[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
        ll v = max({a[i][0], a[i][1], a[i][2]});
        res += v;
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == v)
            {
                q[j].push(max(a[i][(j + 1) % 3], a[i][(j + 2) % 3]) - a[i][j]);
                break;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        while (((int)q[j].size()) > n / 2)
        {
            res += q[j].top();
            q[j].pop();
        }
    }
    cout << res << '\n';
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
