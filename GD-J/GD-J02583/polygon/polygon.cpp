#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5005;
const int mod = 998244353;
int n, a[MAXN];
int tree[MAXN];
#define lowbit(x) (x & -x)
inline void add(int x, const int &d)
{
    while (x < MAXN)
    {
        (tree[x] += d) %= mod;
        x += lowbit(x);
    }
}
inline int query(int x)
{
    int res = 0;
    while (x)
    {
        (res += tree[x]) %= mod;
        x -= lowbit(x);
    }
    return res;
}
inline void Do(const int &v)
{
    for (int i = MAXN - 1; i; --i)
    {
        int now = query(i) - query(i - 1);
        add(min(i + v, MAXN - 1), now);
    }
    add(v, 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    Do(a[1]), Do(a[2]);
    int ans = 0;
    for (int i = 3; i <= n; ++i)
    {
        (ans += query(MAXN - 1) - query(a[i])) %= mod;
        Do(a[i]);
    }
    cout << (ans % mod + mod) % mod << '\n';
    return 0;
}