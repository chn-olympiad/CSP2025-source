#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],s[105],r,l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> s[i];
    }
    r = s[1];
    l = n * m;
    sort(s+1,s+(n * m)+1);
    for (int i = 1;i <= n;i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 1;j <= m;j++)
            {
                a[j][i] = s[l];
                l--;
            }
        }
        else
        {
            for (int j = m;j >= 1;j--)
            {
                a[j][i] = s[l];
                l--;
            }
        }
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (a[i][j] == r)
            {
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
