#include <bits/stdc++.h>
using namespace std;

int a1[10005],a2[10005], b[1005][1005];
int n, m;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n * m; i++)
    {
        cin >> a1[i];
    }

    // 从大到小排列
    sort(a1 + n, a1 + n * m + 1);
    for (int i = n * m; i >= 1; i--)
    {
        a2[i] = a1[n * m + 1 - i];
    }

    // 按成绩以“S”形排列
    int last = 1;
    for (int i = 1; i <= m; i++)
    {
        if (last % 2 == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                b[j][i] = a2[(i - 1) * 3 + j];
            }
        }
        else
        {
            for (int j = last; j >= 1; j++)
            {
                b[j][i] = a2[(i - 1) * 3 + j];
            }
        }
        last++;
    }

    // 遍历查询小R成绩所对应的位置
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j] == a[1])
            {
                cout << i <<  " " << j;
                break;
            }
        }
        break;
    }

    return 0;
}
