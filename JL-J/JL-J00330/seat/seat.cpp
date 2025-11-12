#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x = 0,y = 0,z = 1;
    cin >> n >> m;
    int a[n * m],b[n * m],c[n][m];
    cin >> a[1];
    b[1] = a[1];
    for (int i = 2;i <= n * m;i++)
    {
        cin >> a[i];
        b[i] = a[i];
        if (b[i - 1] < b[i])
        {
            int t = b[i];
            b[i] = b[i - 1];
            b[i - 1] = t;
        }
    }
    for (int i = 1;i <= m;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            c[j][i] = b[z];
            z++;
            if (a[1] == c[j][i])
            {
                cout << i << " " << j;
            }
        }
        i++;
        for (int j = n;j >= 1;j--)
        {
            c[j][i] = b[z];
            z++;
            if (a[1] == c[j][i])
            {
                cout << i << " " << j;
            }
        }
    }
    return 0;
}
