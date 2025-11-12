#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][3], chos[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int _;
    cin >> _;
    while (_ --)
    {
        int n, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        int cnt[3] = {0, 0, 0};
        for (int i = 1; i <= n; i ++)
        {
            if (a[i][0] == max({a[i][0], a[i][1], a[i][2]}))
            {
                cnt[0] ++;
                sum += a[i][0];
                chos[i] = 0;
            }
            else if (a[i][1] == max({a[i][0], a[i][1], a[i][2]}))
            {
                cnt[1] ++;
                sum += a[i][1];
                chos[i] = 1;
            }
            else if (a[i][2] == max({a[i][0], a[i][1], a[i][2]}))
            {
                cnt[2] ++;
                sum += a[i][2];
                chos[i] = 2;
            }
        }
        int mx = max({cnt[0], cnt[1], cnt[2]}), p;
        if (mx <= n / 2)
        {
            cout << sum << endl;
            continue;
        }
        if (cnt[0] == mx)
            p = 0;
        else if (cnt[1] == mx)
            p = 1;
        else
            p = 2;
        vector <int> v;
        for (int i = 1; i <= n; i ++)if (chos[i] == p)
        {
            int smx = 0;
            for (int j = 0; j < 3; j ++) if (j != p)
                smx = max(smx, a[i][j]);
            v.push_back(a[i][p] - smx);
        }
        sort(v.begin(), v.end());
        mx -= n / 2;
        for (int i = 0; i < mx; i ++)
            sum -= v[i];
        cout << sum << endl;
    }
    return 0;
}