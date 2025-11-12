#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[105], s, num;

bool cmp(int x, int y)
{
     return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++) cin >> a[i];
    s = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1;i <= n * m;i++)
    {
        if (a[i] == s)
        {
            num = i;
            break;
        }
    }
    bool flag = true;
    for (int i = 1;i <= m;i++)
    {
        if (flag)
        {
            for (int j = 1;j <= n;j++)
            {
                if (n * (i-1) + j == num)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
        else
        {
        int cnt = 0;
            for (int j = n;j >= 1;j--)
            {
                ++cnt;
                if (n * (i-1) + cnt == num)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
        flag = !flag;
    }
    return 0;
}
