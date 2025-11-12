#include <bits/stdc++.h>
using namespace std;

struct st
{
    int x, y;
};

bool comp(st a, st b)
{
    return a.x > b.x;
}

void solve()
{
    int n;
    cin >> n;
    st a[n], b[n], c[n];
    bool ok[n];
    for (int i = 0; i < n; i++)
        ok[i] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> b[i].x >> c[i].x;
        a[i].y = 0;
        b[i].y = 0;
        c[i].y = 0;
    }
    sort(a, a + n, comp);
    sort(b, b + n, comp);
    sort(c, c + n, comp);
    int ans = 0;
    int t = n;
    int ai = 0, bi = 0, ci = 0;
    int an = 0, bn = 0, cn = 0;
    while (t--)
    {
        while (!ok[a[ai].y])
        {
            ai++;
            if (ok[a[ai].y])
                break;
            if (ai >= n)
            {
                ai = 0;
                break;
            }
        }
        while (!ok[b[bi].y])
        {
            bi++;
            if (ok[b[bi].y])
                break;
            if (bi >= n)
            {
                bi = 0;
                break;
            }
        }
        while (!ok[c[ci].y])
        {
            ci++;
            if (ok[c[ci].y])
                break;
            if (ci >= n)
            {
                ci = 0;
                break;
            }
        }
        if(a[ai].x >= b[bi].x && a[ai].x >= c[ci].x && an <= 2 / n && ok[a[ai].y])
        {
            ans += a[ai].x;
            an++;
            ok[a[ai].y] = 0;
        }
        else if(b[bi].x >= a[ai].x && b[bi].x >= c[ci].x && bn <= 2 / n && ok[b[bi].y])
        {
            ans += b[bi].x;
            bn++;
            ok[b[bi].y] = 0;
        }
        else if(c[ci].x >= b[bi].x && c[ci].x >= a[ai].x && cn <= 2 / n && ok[c[ci].y])
        {
            ans += c[ci].x;
            cn++;
            ok[c[ci].y] = 0;
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
