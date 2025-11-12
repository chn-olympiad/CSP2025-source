#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
struct node
{
    int x, y, z;
};

node a[N];
int b[N], c[N], d[N];
int n;

int solve()
{
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        d[i] = b[i] - c[i];
        t += b[i];
    }
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n / 2; i++) t -= d[i];
    return t;

}


int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].x >> a[i].y >> a[i].z;
            /*
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i].x;
            c[i] = max(a[i].z, a[i].y);
        }
        int ans = solve();
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i].y;
            c[i] = max(a[i].x, a[i].z);
        }
        ans = max(ans, solve());
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i].z;
            c[i] = max(a[i].y, a[i].x);
        }
        ans = max(ans, solve());
        */
        int ans = 0;
        int A = 0, B = 0, C = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].x > max(a[i].y, a[i].z)) A++;
            if (a[i].y > max(a[i].x, a[i].z)) B++;
            if (a[i].z > max(a[i].x, a[i].y)) C++;
            ans += max(max(a[i].x, a[i].y), a[i].z);
        }
        if (A > n / 2)
        {
            for (int i = 1; i <= n; i++)
            {
                b[i] = a[i].x;
                c[i] = max(a[i].z, a[i].y);
            }
            cout << solve() << endl;
        }
        else if (B > n / 2)
        {
            for (int i = 1; i <= n; i++)
            {
                b[i] = a[i].y;
                c[i] = max(a[i].x, a[i].z);
            }
            cout << solve() << endl;
        }
        else if (C > n / 2)
        {
            for (int i = 1; i <= n; i++)
            {
                b[i] = a[i].z;
                c[i] = max(a[i].y, a[i].x);
            }
            cout << solve() << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
