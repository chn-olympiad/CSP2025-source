#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];
int ans[15][15];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int num = n * m;
    for (int i = 1; i <= num; i ++)
        cin >> a[i];
    int M = a[1];
    sort(a + 1, a + num + 1, cmp);
    for (int i = 1; i <= num; i ++)
    {
        int lie = (i - 1) / n + 1, hang = 0;
        if (lie % 2 == 1)
        {
            if (i % n == 0)
                hang = n;
            else
                hang = i % n;
        }
        else
        {
            if (i % n == 0)
                hang = 1;
            else
                hang = n - (i % n - 1);
        }
        ans[hang][lie] = a[i];
    }
    for (int i = 0; i <= 14; i ++)
        for (int j = 0; j <= 14; j ++)
            if (ans[i][j] == M)
                cout << i << ' ' << j;
    return 0;
}
