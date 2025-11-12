#include <bits/stdc++.h>
using namespace std;
int n , m , cj;

bool cmp(int i , int j)
{
    return i > j;
}

int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    int a[n * m + 2] , x[n + 2][m + 2];
    for (int i = 0;i < n * m;i++)
    {
        cin >> a[i];
    }
    cj = a[0];
    sort (a , a + n * m , cmp);
    int k = 0;
    for (int i = 0;i < m;i++)
    {
        if ((i + 1) % 2 == 0)
        {
            for (int j = n - 1;j >= 0;j--)
            {
                x[j][i] = a[k];
                k++;
            }
        }
        else
        {
            for (int j = 0;j < n;j++)
            {
                x[j][i] = a[k];
                k++;
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if(x[i][j] == cj)
            {
                cout << j + 1 << " " << i + 1;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
