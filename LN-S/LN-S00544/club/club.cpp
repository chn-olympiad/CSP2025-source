#include <iostream>
using namespace std;
int a[100000][3], m[100000];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, d0 = 0, d1 = 0, d2 = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            ans += max(max(a[i][0], a[i][1]), a[i][2]);
            m[i] = (a[i][0] > a[i][1] ? a[i][0] > a[i][2] ? 0 : a[i][0] < a[i][2] ? 2 : d0 < d2 ? 0 : 2 : a[i][0] < a[i][1] ? a[i][1] > a[i][2] ? 1 : a[i][1] < a[i][2] ? 2 : d1 < d2 ? 1 : 2 : d0 < d1 ? 0 : 1);
            (m[i] ? m[i] == 1 ? d1 : d2 : d0)++;
        }
        if (d0 > n / 2)
        {
            int tgt = d0 - n / 2;
            while (tgt--)
            {
                int sum = 2147483647, p = -1;
                for (int i = 0; i < n; i++)
                    if (m[i] == 0 && a[i][0] - max(a[i][1], a[i][2]) < sum)
                    {
                        sum = a[i][0] - max(a[i][1], a[i][2]);
                        p = i;
                    }
                ans = ans - a[p][0] + max(a[p][1], a[p][2]);
                m[p] = (a[p][1] > a[p][2] ? 1 : 2);
            }
        }
        if (d1 > n / 2)
        {
            int tgt = d1 - n / 2;
            while (tgt--)
            {
                int sum = 2147483647, p = -1;
                for (int i = 0; i < n; i++)
                    if (m[i] == 1 && a[i][1] - max(a[i][0], a[i][2]) < sum)
                    {
                        sum = a[i][1] - max(a[i][0], a[i][2]);
                        p = i;
                    }
                ans = ans - a[p][1] + max(a[p][0], a[p][2]);
                m[p] = (a[p][0] > a[p][2] ? 0 : 2);
            }
        }
        if (d2 > n / 2)
        {
            int tgt = d2 - n / 2;
            while (tgt--)
            {
                int sum = 2147483647, p = -1;
                for (int i = 0; i < n; i++)
                    if (m[i] == 2 && a[i][2] - max(a[i][1], a[i][0]) < sum)
                    {
                        sum = a[i][2] - max(a[i][1], a[i][0]);
                        p = i;
                    }
                ans = ans - a[p][2] + max(a[p][1], a[p][0]);
                m[p] = (a[p][0] > a[p][1] ? 0 : 1);
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
