#include<bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>m;
    int a[n][m], c[n * m], d[n * m], r = 1, t = 0;
    for(int i = 1; i <= n * m; i++)
    {
            cin>>c[i];
    }
    int cnt1 = c[1];

    for(int i = 1; i <= n * m; i++)
    {
            int x = 0, y = 1;
            for(int p = 1; p <= n * m; p++)
            {
                if(c[p] != 10)
                {
                    x = c[p];
                    break;
                }
            }

            for(int p = 1; p <= n * m; p++)
            {
                if(c[p] != -1)
                {
                    if(x < c[p])
                    {
                        x = c[p];
                        y = p;
                    }
                }
            }
            c[y] = -1;
            d[i] = x;
    }

    for(int i = 1; i <= n; i++)
    {
        if(t == 0)
        {
            for(int j = 1; j <= m; j++)
            {
                t++;
                a[i][t] = d[r];
                r++;
            }
        }
        else if(t == m)
        {
            for(int j = 1; j <= m; j++)
            {
                a[i][t] = d[r];
                t--;
                r++;
            }
        }
    }

    int cnt2 = 0, cnt3 = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == cnt1)
            {
                cnt2 = i;
                cnt3 = j;
            }
        }
    }
    cout<<cnt2<<" "<<cnt3;
    return 0;
}
