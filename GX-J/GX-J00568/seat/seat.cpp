#include <bits//stdc++.h>
using namespace std;
int a[15][15] , n , m , b[398];
int mian()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m ;i++)
    {
        cin >> b[i];
    }
    int z = b[1];
    for(int i = 1;i <= n*m;i++)
    {
        if(b[i] < b[i+1])
        {
            int t = b[i];
            b[i] = b[i+1];
            b[i+1] = t;
        }
    }
    int k = 1;
    for (int i = 1;i <= m;i++)
    {
        if(i % 2 == 1)
        {
            for (int j = i;j <= n;j++)
            {
                a[j][m] = b[k];
                k++;
                if(b[k] == z)
                    cout << a[j][m];
            }
        }
        else
        {
            for (int j = n;j >= 1;j--)
            {
                a[j][m] = b[k];
                k++;
                if(b[k] == z)
                    cout << a[j][m];
            }
        }
    }
    return 0;
}
