#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1,cnt = 1,num = 1;
    cin >> n >> m;
    int a[n][m];
    int b[n*m];
    for(int i = 1;i <= m * n;i++)
    {
        cin >> b[i];
    }
    a1 = b[1];
    sort(b + 1,b + n*m + 1);
    for(int i = n*m;i >= 1;i--)
    {
        if(b[i] == a1)
        {
            break;
        }
        cnt++;
    }
    for(int i = 1;i <= m;i++)
    {
        if(i % 2 == 0)
        {
            for(int j = n; j >= 1;j--)
            {
                if(num == cnt)
                {
                    cout << i << ' ' << j;
                    return 0;
                }
                else
                {
                    num++;
                }
            }
        }
        else
        {
            for(int j = 1; j <= n;j++)
            {
                if(num == cnt)
                {
                    cout << i << ' ' << j;
                    return 0;
                }
                else
                {
                    num++;
                }
            }
        }
    }
}

