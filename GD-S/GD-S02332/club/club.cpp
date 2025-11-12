#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, a[MAXN][3];
struct node
{
    int a, b, c;
    node() {}
    node(const int &x, const int &y, const int &z) : a(x), b(y), c(z) {}
};
vector<node> x, y, z;
inline void Main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    x.clear(), y.clear(), z.clear();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int maxn = max({a[i][0], a[i][1], a[i][2]});
        if (a[i][0] == maxn)
            x.emplace_back(a[i][0], a[i][1], a[i][2]);
        else if (a[i][1] == maxn)
            y.emplace_back(a[i][0], a[i][1], a[i][2]);
        else
            z.emplace_back(a[i][0], a[i][1], a[i][2]);
        ans += maxn;
    }
    int maxn = max({x.size(), y.size(), z.size()});
    if (maxn > (n >> 1))
    {
        if (x.size() < y.size())
            x.swap(y);
        if (x.size() < z.size())
            x.swap(z);
        sort(x.begin(), x.end(), [](const node &i, const node &j)
             {
                int tmp1 = i.a + i.b + i.c - max({i.a, i.b, i.c}) - min({i.a, i.b, i.c}), tmp2 = j.a + j.b + j.c - max({j.a, j.b, j.c}) - min({j.a, j.b, j.c});
                return max({i.a, i.b, i.c}) - tmp1 < max({j.a, j.b, j.c}) - tmp2; });
        for (int i = 0; i + (n >> 1) < (int)x.size(); ++i)
            ans = ans - max({x[i].a, x[i].b, x[i].c}) + (x[i].a + x[i].b + x[i].c - max({x[i].a, x[i].b, x[i].c}) - min({x[i].a, x[i].b, x[i].c}));
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
        Main();
    return 0;
}