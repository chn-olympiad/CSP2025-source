#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in" , "w" , stdin);
    freopen("seat.out" , "r" , stdout);
    int a[10][10] , n , m , c , r;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <+ m ; j++)
        {
            cin >> a[i][j];
        }
    }
    int min = 10000;
    while (a[m][n] = min)
    {
        for (int i = 1 ; i <= m ; i++)
        {

            if (m % 2 == 0)
            {
                for (int j = n ; j >= 1 ; j--)
                {
                    if (a[i][j] < a[i + 1][j])
                    {
                        int t = a[i][j];
                        a[i][j] = a[i][j + 1];
                        a[i][j + 1] = t;
                    }
                }
            }
            else
            {
                for (int j = 1 ; j <= n ; j++)
                {
                    if (a[i][j] < a[i + 1][j])
                    {
                        int t = a[i][j];
                        a[i][j] = a[i][j + 1];
                        a[i][j + 1] = t;
                    }
                }
            }
        }
    }
    cout << a[c][r];
    return 0;
}
