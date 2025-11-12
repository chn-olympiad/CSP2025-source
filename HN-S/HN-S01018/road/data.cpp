#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmin(T &x, T y) {return (y < x) && (x = y, true);}
template <typename T> inline bool ckmax(T &x, T y) {return (x < y) && (x = y, true);}
mt19937 rnd(random_device{}());
int n = 10000, m = 1000000, k = 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << n << ' ' << m << ' ' << k << '\n';
    for (int i = 2; i <= n; ++ i) cout << rnd() % (i - 1) + 1 << ' ' << i << ' ' << rnd() % 1000000000 + 1 << '\n';
    for (int i = n, u, v; i <= m; ++ i)
    {
        u = rnd() % n + 1, v = rnd() % n + 1;
        while (u == v) v = rnd() % n + 1;
        cout << u << ' ' << v << ' ' << rnd() % 1000000000 + 1 << '\n';
    }
    for (int i = 1; i <= k; ++ i)
    {
        cout << rnd() % 1000000000 + 1 << ' ';
        for (int j = 1; j <= n; ++ j) cout << rnd() % 1000000000 + 1 << ' ';
        cout << '\n';
    }
    return 0;
}