`#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1100];

int main()
{
    freopen("number.in","r",number.in);
    freopen("number.out","w",number.out);
    cin >> n >> m;
    for (int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int x = a[1];
    sort (a[1], a[n*m+1]);
    int i = 1, j = 1;
    b[1][1] = a[1];
    for (int c = 2;c <= n+1;i++)
    {
        if (i + 1 <= n)
        {
            b[i][j] = a[i];
            continue;
        }
        if (i + 1 > n)
        {
            j + 1;
            b[i][j] = a[i];
            continue;
        }
    }
    for (int i = n+2;i <= ;i++)
    {

    }

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (b[i][j] = a[i])
            {
                cout << i << " " << j;
                break;
            }
        }
    }
    return 0;
}
