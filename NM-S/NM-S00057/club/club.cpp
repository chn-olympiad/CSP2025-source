#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a, b, c;
    bool operator<(const node &b) const { return a > b.a; }
};
int n;
vector<node> a;
int ans;
constexpr int N = 2e4 + 1, M = 1e5 + 1;
inline int dfs(int x, int sum, int suma, int sumb, int sumc)
{
    if (suma > n / 2 || sumb > n / 2 || sumc > n / 2)
    {
        return 0;
    }
    if (x > n)
    {
        return sum;
    }
    return max({
        dfs(x + 1, sum + a[x].a, suma + 1, sumb, sumc),
        dfs(x + 1, sum + a[x].b, suma, sumb + 1, sumc),
        dfs(x + 1, sum + a[x].c, suma, sumb, sumc + 1),
    });
}
inline int dfs(int x, int sum, int suma, int sumb)
{
    if (suma > n / 2 || sumb > n / 2)
    {
        return 0;
    }
    if (x > n)
    {
        return sum;
    }
    return max({
        dfs(x + 1, sum + a[x].a, suma + 1, sumb),
        dfs(x + 1, sum + a[x].b, suma, sumb + 1),
    });
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
        ans = 0;
        cin >> n;
        a = vector<node>(n + 1, {0, 0, 0});
        bool fl = 0, fl1 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].a >> a[i].b >> a[i].c;
            if (a[i].b != 0 || a[i].c != 0)
            {
                fl = 1;
            }
            if (a[i].c != 0)
            {
                fl1 = 1;
            }
        }
        if (!fl)
        {
            long long ans = 0;
            sort(a.begin() + 1, a.end());
            for (int i = 1; i <= n / 2; i++)
            {
                ans += a[i].a;
            }
            cout << ans << '\n';
        }
        else if (!fl1)
        {
            cout << dfs(1, 0, 0, 0);
        }
        else
            cout << dfs(1, 0, 0, 0, 0) << '\n';
    }
}