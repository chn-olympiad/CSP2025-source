#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],c[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    cin >> n >> m;
    int N = n * m;
    for (int i = 1;i <= N;i++)
    {
        cin >> c[i];
    }
    int s = c[1],j = 1;
    sort(c+1,c+N+1);
    for (int i = N;i >= 1;i--)
    {
        a[j++] = c[i];
    }
    int cnt = 1;
    for (int i = 1;i <= m;i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1;j <= n;j++)
            {
                b[j][i] = a[cnt++];
            }
        }
        else
        {
            for (int j = n;j >= 1;j--)
            {
                b[j][i] = a[cnt++];
            }
        }
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (b[i][j] == s)
            {
                cout << j << " " << i;
            }
        }
    }
    return 0;
}
