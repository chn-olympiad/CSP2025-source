#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cctype>

using namespace std;

constexpr int maxn = 100000;
int a[maxn + 5][4], tp[maxn + 5], id[maxn + 5];

int read()
{
    char ch;
    while ((ch = getchar()) && !isdigit(ch));
    int ans = ch - '0';
    while ((ch = getchar()) && isdigit(ch))
        ans = ans * 10 + ch - '0';
    return ans;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t = read();
    while (t--)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++)
                a[i][j] = read();
        
        int ans = 0, c1 = 0, c2 = 0, c3 = 0;
        for (int i = 1; i <= n; i++)
        {
            int maxv = max({a[i][1], a[i][2], a[i][3]});
            ans += maxv;
            if (maxv == a[i][1])
            {
                c1++;
                tp[i] = 1;
            }
            else if (maxv == a[i][2])
            {
                c2++;
                tp[i] = 2;
            }
            else
            {
                c3++;
                tp[i] = 3;
            }
            sort(a[i] + 1, a[i] + 4);
        }

        if ((c1 << 1) > n || (c2 << 1) > n || (c3 << 1) > n)
        {
            int val = 0, cnt = 0;
            if ((c1 << 1) > n)
            { val = 1; cnt = c1; }
            else if ((c2 << 1) > n)
            { val = 2; cnt = c2; }
            else
            { val = 3; cnt = c3; }

            iota(id + 1, id + n + 1, 1);
            sort(id + 1, id + n + 1, [](int x, int y) { return a[x][3] - a[x][2] < a[y][3] - a[y][2]; });

            for (int i = 1; i <= n && (cnt << 1) > n; i++)
                if (tp[id[i]] == val)
                {
                    ans -= a[id[i]][3] - a[id[i]][2];
                    cnt--;
                }
        }
        cout << ans << endl;
    }

    return 0;
}