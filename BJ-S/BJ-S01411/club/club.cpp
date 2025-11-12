#include <bits/stdc++.h>
using namespace std;
struct node
{
    int f, s, t;
}a[100005];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int cntf = 0, cnts = 0, cntt = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].f >> a[i].s >> a[i].t;
            if (a[i].f >= a[i].s && a[i].f >= a[i].t && cntf < n / 2) cntf++, ans += a[i].f;
            else if (a[i].s >= a[i].t && cnts < n / 2) cnts++, ans += a[i].s;
            else cntt++, ans += a[i].t;
        }
        cout << ans << endl;
    }
    return 0;
}
