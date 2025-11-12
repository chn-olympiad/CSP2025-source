#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn], c[maxn], cnt[3];
signed main ()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= b[i] && a[i] >= c[i]) cnt[0]++;
            else if (b[i] >= a[i] && b[i] >= c[i]) cnt[1]++;
            else cnt[2]++;
        }
        if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
        {
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] >= b[i] && a[i] >= c[i]) ans += a[i];
                else if (b[i] >= a[i] && b[i] >= c[i]) ans += b[i];
                else ans += c[i];
            }
            cout << ans << endl;
        }
        else if (cnt[0] > n / 2)
        {
            int ans = 0;
            vector<int> v;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] >= b[i] && a[i] >= c[i])
                {
                    ans += a[i];
                    v.push_back(min(a[i] - b[i], a[i] - c[i]));
                }
                else if (b[i] >= a[i] && b[i] >= c[i]) ans += b[i];
                else ans += c[i];
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < cnt[0] - n / 2; i++) ans -= v[i];
            cout << ans << endl;
        }
        else if (cnt[1] > n / 2)
        {
            int ans = 0;
            vector<int> v;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] >= b[i] && a[i] >= c[i]) ans += a[i];
                else if (b[i] >= a[i] && b[i] >= c[i])
                {
                    ans += b[i];
                    v.push_back(min(b[i] - a[i], b[i] - c[i]));
                }
                else ans += c[i];
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < cnt[1] - n / 2; i++) ans -= v[i];
            cout << ans << endl;
        }
        else if (cnt[2] > n / 2)
        {
            int ans = 0;
            vector<int> v;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] >= b[i] && a[i] >= c[i]) ans += a[i];
                else if (b[i] >= a[i] && b[i] >= c[i]) ans += b[i];
                else
                {
                    ans += c[i];
                    v.push_back(min(c[i] - a[i], c[i] - b[i]));
                }
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < cnt[2] - n / 2; i++) ans -= v[i];
            cout << ans << endl;
        }
    }
    return 0;
}
