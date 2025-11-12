#include <bits/stdc++.h>

using namespace std;

namespace langfengya
{
    void Main();
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    langfengya::Main();
    return 0;
}

namespace langfengya
{
    int t;
    int n;
    const int N = 1e5 + 10;
    int a[N][10];
    int maxn[N], minx[N];
    int fir = 0, sec = 0, thi = 0;
    int cnt1[N], cnt2[N], cnt3[N];
    int sum = 0;
    void read()
    {
        cin >> n;
        fir = 0, sec = 0, thi = 0;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            maxn[i] = max(a[i][1], max(a[i][2], a[i][3]));
            if (maxn[i] == a[i][1])
            {
                minx[i] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
                cnt1[++fir] = minx[i];
            }
            else if (maxn[i] == a[i][2])
            {
                minx[i] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
                cnt2[++sec] = minx[i];
            }
            else
            {
                minx[i] = min(a[i][3] - a[i][2], a[i][3] - a[i][1]);
                cnt3[++thi] = minx[i];
            }
            sum += maxn[i];
        }
    }
    void solve()
    {
        if (fir > n / 2)
        {
            sort(cnt1 + 1, cnt1 + fir + 1);
            for (int i = 1; i <= fir - n / 2; i++)
            {
                sum -= cnt1[i];
            }
        }
        else if (sec > n / 2)
        {
            sort(cnt2 + 1, cnt2 + sec + 1);
            for (int i = 1; i <= sec -  n / 2; i++)
            {
                sum -= cnt2[i];
            }
        }
        else if (thi > n / 2)
        {
            sort(cnt3 + 1, cnt3 + thi + 1);
            for (int i = 1; i <= thi - n / 2; i++)
            {
                sum -= cnt3[i];
            }
        }
        cout << sum << endl;
    }
    void Main()
    {
        cin >> t;
        while (t--)
        {
            read();
            solve();
        }
    }
}