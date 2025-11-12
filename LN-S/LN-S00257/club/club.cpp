#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 200001;

int t, n, ans, ca, cb, cc, pa, pb, pc, a[MAX_N], b[MAX_N], c[MAX_N], da[MAX_N], db[MAX_N], dc[MAX_N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t --> 0)
    {
        ans = 0;
        ca = 0;
        cb = 0;
        cc = 0;
        pa = 0;
        pb = 0;
        pc = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            if ((a[i] == b[i] && a[i] > c[i]) || (a[i] == c[i] && a[i] > b[i]))  { ans += a[i]; }
            else if (b[i] == c[i] && b[i] > a[i])  { ans += b[i]; }
            else if (a[i] > b[i] && a[i] > c[i])
            {
                ca++;
                ans += a[i];
                da[++pa] = a[i] - max(b[i], c[i]);
            }
            else if (b[i] > a[i] && b[i] > c[i])
            {
                cb++;
                ans += b[i];
                db[++pb] = b[i] - max(a[i], c[i]);
            }
            else
            {
                cc++;
                ans += c[i];
                dc[++pc] = c[i] - max(a[i], b[i]);
            }
        }
        if (max({ ca, cb, cc }) <= n / 2)  { cout << ans << endl; }
        else
        {
            if (ca > n / 2)
            {
                sort(da + 1, da + pa + 1);
                pa = 0;
                while (ca > n / 2)
                {
                    ans -= da[++pa];
                    ca--;
                }
            }
            else if (cb > n / 2)
            {
                sort(db + 1, db + pb + 1);
                pb = 0;
                while (cb > n / 2)
                {
                    ans -= db[++pb];
                    cb--;
                }
            }
            else
            {
                sort(dc + 1, dc + pc + 1);
                pc = 0;
                while (cc > n / 2)
                {
                    ans -= dc[++pc];
                    cc--;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
