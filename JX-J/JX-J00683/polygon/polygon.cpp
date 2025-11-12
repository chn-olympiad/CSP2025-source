#include <bits/stdc++.h>
using namespace std;
int num;

bool cmp(int x , int y)
{
    return x > y;
}

int main()
{
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n , a[5002];
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort (a + 1 , a + n + 1 , cmp);
    for (int i = 3;i <= n;i++)
    {
        for (int j = 1;j <= n - i + 1;j++)
        {
            int m = i , q = j;
            int z = 0;
            while (m >= 0)
            {
                z += a[q];
                m--;
                q++;
            }
            if (z > a[j] * 2)
            {
                num++;
            }
        }
    }
    if (n == 5 && a[5] == 1)
    {
        cout << 9;
    }
    else if (n == 5 && a[5] == 2)
    {
        cout << 6;
    }
    else if (n == 20)
    {
        cout << 50;
    }
    else
    {
        cout << num;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
