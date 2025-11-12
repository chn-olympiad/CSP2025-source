#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],b[1000055];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> b[i];
    }
    int x = b[1];
    sort(b,b + n*m + 1);
    int c[m*n + 10];
    int res = 0;
    for (int i = n * m;i >= 1;i--)
    {
        res++;
        c[res] = b[i];
    }
    bool flag = 1;//0shang 1xia
    int k = 0;
    for (int i = 1;i <= m;i++)
    {
        if (flag == 1)
        {
            for (int j = 1;j <= n;j++)
            {
                k++;
                if (c[k] == x)
                {
                    cout << i << " " << j;
                    return 0;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        else
        {
            for (int j = n;j >= 1;j--)
            {
                k++;
                if (c[k] == x)
                {
                    cout << i << " " << j;
                    return 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
    }
    return 0;
}
