#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
int a[110];
int s[20][20];
int main()
{
    freopen("seat.in", "r", std.in);
    freopen("seat.out", "w", std.out);
    int m, n, tt;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    tt = a[1];
    sort(a+1, a+n*m+1,cmp);
    for(int k = 1; k <= n * m; k++)
    {
        for(int i = 1; i <= n*m; i++)
        {
            if(i % 2 == 0)
            {
                for(int j = n*m; j >= 1; j--)
                {
                    cout << i << " " << j;
                }
            }
            else
            {
                for(int j = 1; j <= n*m; j++)
                {
                    cout << i << " " << j;
               }
            }
        }
    }
    return 0;
    }
