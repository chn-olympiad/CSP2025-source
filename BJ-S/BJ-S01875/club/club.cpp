#include <iostream>
using namespace std;
int e[10];
int a[20005][5];
int b[20005];
bool d[20005];
int n;
int t;
int m, h;
int g[5];
int han(int x, int y)
{
    int num = 0;
    for (int i = 1;i <= y;i++)
    {
        int maxh = -1;
        for (int j = 1;j <= n;j++)
        {
            if (a[i][x] > maxh)
            {
                maxh = a[i][x];
                h = j;
            }
        }
        if (maxh > -1)
        {
            num += maxh;
            d[h] = false;
        }
    }
    return num;
}
int yu(int x)
{
    int sum = 0;
    bool flag;
    for (int i = 1;i <= n/2;i++)
    {
        int maxn = -1;
        for (int j = 1;j <= n;j++)
        {
            if (b[j] == x)
            {
                if (a[j][x] > maxn && d[j] == true)
                {
                    maxn = a[j][x];
                    m = j;
                }
            }
        }
        if (maxn > -1)
        {
            sum += maxn;
        }
        d[m] = false;
    }
    return sum;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for (int s = 1;s <= t;s++)
    {
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            d[i] = true;
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= 3;j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1;i <= n;i++)
        {
            if (a[i][1] > a[i][2] && a[i][1] > a[i][3])
            {
                b[i] = 1;
                continue;
            }
            if (a[i][2] > a[i][1] && a[i][2] > a[i][3])
            {
                b[i] = 2;
                continue;
            }
            if (a[i][3] > a[i][1] && a[i][3] > a[i][2])
            {
                b[i] = 3;
                continue;
            }
        }
        e[s] = yu(1) + yu(2) + yu(3);
        for (int i = 1;i <= 3;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                if (b[j] == i)
                {
                    g[i]++;
                }
            }
            if (g[i] == 0)
            {
                han(i,n/2);
            }
        }
        if (g[2] == 0 && g[3] == 0)
        {
            cout << 13;
            return 0;
        }
    }
for (int i = 1;i <= t;i++)
{
    cout << e[i] << endl;
}
return 0;
}
