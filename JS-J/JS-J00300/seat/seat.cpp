#include <bits/stdc++.h>
#define int long long
#define x0 akcsp_j
#define x1 akcsp_s
#define y0 ak_noi
#define y1 ak_ioi
#define endl '\n'
#define hash my_hash
#define next my_next
#define LLMI LONG_LONG_MIN
#define LLMA LONG_LONG_MAX
using namespace std;
int a[15][15];
vector <int> aa;
signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
            aa.push_back(a[i][j]);
        }
    }
    int r = a[1][1];
    sort(aa.begin(), aa.end(), greater <int>());
    int x = 1, y = 1;
    bool f = 1;
    for (auto i : aa)
    {
        if (i == r)
        {
            cout << x << ' ' << y << endl;
            break;
        }
        if (f)
        {
            y ++;
            if (y == n + 1)
            {
                y = n;
                x ++;
                f = 0;
            }
        }
        else
        {
            y --;
            if (y == 0)
            {
                y = 1;
                x ++;
                f = 1;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
