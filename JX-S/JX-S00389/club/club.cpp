#include <bits/stdc++.h>

using namespace std;
#define int long long
//struct node
//{
//    int as, bs, cs, x;
//}a1[100010][3], b1[100010][3], c1[100010][3];
int a[100010], b[100010], c[100010], ans, n;
void dfs(int as, int bs, int cs, int l, int id, int sum)
{
    ans = max(ans, sum);
    if (id > n) return;
    if (as < l) dfs(as + 1, bs, cs, l, id + 1, sum + a[id]);
    if (bs < l) dfs(as, bs + 1, cs, l, id + 1, sum + b[id]);
    if (cs < l) dfs(as, bs, cs + 1, l, id + 1, sum + c[id]);
}
void dfs1(int as, int bs, int cs, int l, int id, int sum)
{
    ans = max(ans, sum);
    if (id > n) return;
    if (as < l) dfs(as + 1, bs, cs, l, id + 1, sum + a[id]);
    if (bs < l) dfs(as, bs + 1, cs, l, id + 1, sum + b[id]);
}
void solve()
{
    cin >> n;
    int l = n / 2;
    ans = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
    dfs(0, 0, 0, l, 1, 0);
    cout << ans << endl;
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int l = n / 2, cnt = 0, cnt1 = 0;
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i] >> b[i] >> c[i];
            if (b[i] == 0 && c[i] == 0) ++cnt;
            else if (!b[i]) ++cnt1;
        }
        if (cnt == n)
        {
            sort(a + 1, a + n + 1, greater<int>());
            for (int i = 1; i <= l; ++i) ans += a[i];
            cout << ans << endl;
            continue;
        }
        else if (cnt1 == n) dfs1(0, 0, 0, l, 1, 0);
        else dfs(0, 0, 0, l, 1, 0);
        cout << ans << endl;
    }
    return 0;
}
