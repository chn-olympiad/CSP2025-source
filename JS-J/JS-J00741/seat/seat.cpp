#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a[105], seat[15][15], num;
bool cmp(int a, int b)
{
    return a > b;
}
void down_sort(int j)
{
    for (int i = 1; i <= n; i++)
        seat[j][i] = a[++num];
}
void up_sort(int j)
{
    for (int i = n; i >= 1; i--)
        seat[j][i] = a[++num];
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int len = n * m;
    for (int i = 1; i <= len; i++)
        cin >> a[i];
    int pos = a[1];
    sort(a + 1, a + len + 1, cmp);
    for (int j = 1; j <= m; j++)
    {
        if (j % 2 == 1)
            down_sort(j);
        else
            up_sort(j);
    }
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            if (seat[i][j] == pos)
            {
                x = i, y = j;
                break;
            }
    cout << x << " " << y;
    return 0;
}
