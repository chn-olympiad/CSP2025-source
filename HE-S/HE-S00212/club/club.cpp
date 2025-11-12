#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005];
int n;

bool cmp (int a, int b)
{
    return a > b;
}
inline void solve ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    sort (a, a + n, cmp);
    sort (b, b + n, cmp);
    sort (c, c + n, cmp);
    int cnt = 0;
    for (int i = 0; i < (n / 2); i++)
    {
        cnt += a[i];
    }
    cout << cnt << '\n';
    /*for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }

    char s;
    int an = 0, bn = 0, cn = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= b[i] && a[i] >= c[i] && an <= (n / 2) && an <= bn && an <= cn)
        {
            cout << a[i] << " ";
            cnt += a[i];
            an++;
        }
        else if (b[i] >= a[i] && b[i] >= c[i] && bn <= (n / 2) && bn <= cn && bn <= an)
        {
            cout << b[i] << " ";
            cnt += b[i];
            bn++;
        }
        else
        {
            cout << c[i] << " ";
            cnt += c[i];
            cn++;
        }
    }
    cout << cnt << endl;
    return ;
    */
}
int main()
{
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    ios :: sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
