#include <bits/stdc++.h>
using namespace std;
int t;
int n, a[100005][5];
int putin[5][100005];
bool cmp1(int x, int y)
{
    return a[x][1] - max(a[x][2], a[x][3]) > a[y][1] - max(a[y][2], a[y][3]);
}
bool cmp2(int x, int y)
{
    return a[x][2] - max(a[x][1], a[x][3]) > a[y][2] - max(a[y][1], a[y][3]);
}
bool cmp3(int x, int y)
{
    return a[x][3] - max(a[x][1], a[x][2]) > a[y][3] - max(a[y][1], a[y][2]);
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    ++t;
    while (--t)
    {
        putin[1][0] = putin[2][0] = putin[3][0] = 0;
        cin >> n;
        int half = n / 2;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            int ma = max(a[i][1], max(a[i][2], a[i][3]));
            if (ma == a[i][1])
            {
                putin[1][++putin[1][0]] = i;
            }
            else if (ma == a[i][2])
            {
                putin[2][++putin[2][0]] = i;
            }
            else
            {
                putin[3][++putin[3][0]] = i;
            }
        }
        /*
        cout << "1: ";
        for (int i = 1; i <= putin[1][0]; ++i)
        {
            cout << putin[1][i] << ' ';
        }
        cout << '\n';
        cout << "2: ";
        for (int i = 1; i <= putin[2][0]; ++i)
        {
            cout << putin[2][i] << ' ';
        }
        cout << '\n';
        cout << "3: ";
        for (int i = 1; i <= putin[3][0]; ++i)
        {
            cout << putin[3][i] << ' ';
        }
        cout << '\n';
        */
        if (putin[1][0] > half)
        {
            sort(putin[1] + 1, putin[1] + putin[1][0] + 1, cmp1);
            while (putin[1][0] > half)
            {
                if (a[putin[1][putin[1][0]]][2] > a[putin[1][putin[1][0]]][3])
                {
                    putin[2][++putin[2][0]] = putin[1][putin[1][0]];
                    --putin[1][0];
                }
                else
                {
                    putin[3][++putin[3][0]] = putin[1][putin[1][0]];
                    --putin[1][0];
                }
            }
        }
        else if (putin[2][0] > half)
        {
            sort(putin[2] + 1, putin[2] + putin[2][0] + 1, cmp2);
            while (putin[2][0] > half)
            {
                if (a[putin[2][putin[2][0]]][1] > a[putin[2][putin[2][0]]][3])
                {
                    putin[1][++putin[1][0]] = putin[2][putin[2][0]];
                    --putin[2][0];
                }
                else
                {
                    putin[3][++putin[3][0]] = putin[2][putin[2][0]];
                    --putin[2][0];
                }
            }
        }
        else if (putin[3][0] > half)
        {
            sort(putin[3] + 1, putin[3] + putin[3][0] + 1, cmp3);
            while (putin[3][0] > half)
            {
                if (a[putin[3][putin[3][0]]][1] > a[putin[3][putin[3][0]]][2])
                {
                    putin[1][++putin[1][0]] = putin[3][putin[3][0]];
                    --putin[3][0];
                }
                else
                {
                    putin[2][++putin[2][0]] = putin[3][putin[3][0]];
                    --putin[3][0];
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i <= putin[1][0]; ++i)
        {
            ans += a[putin[1][i]][1];
        }
        for (int i = 1; i <= putin[2][0]; ++i)
        {
            ans += a[putin[2][i]][2];
        }
        for (int i = 1; i <= putin[3][0]; ++i)
        {
            ans += a[putin[3][i]][3];
        }
        cout << ans << '\n';
    }
    cout << endl;
    return 0;
}
