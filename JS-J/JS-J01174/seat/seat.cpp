#include <bits/stdc++.h>
using namespace std;
int a[1005];
int b[15][15];
bool cmp(int a , int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int c = a[1];
    sort(a + 1 , a + 1 + n * m , cmp);
    int h = 1;
    for (int j = 1; j <= m; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = n; i >= 1; i--)
            {
                b[i][j] = a[h];
                if (a[h] == c)
                {
                    cout << j << " " << i << endl;
                    return 0;
                }
                h++;
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                b[i][j] = a[h];
                if (a[h] == c)
                {
                    cout << j << " " << i << endl;
                    return 0;
                }
                h++;
            }
        }
    }
    return 0;
}
