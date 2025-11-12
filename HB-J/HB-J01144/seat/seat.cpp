#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[11][11];
    int s[101];
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> s[i];
    }
    int u = s[1];
    for(int i = 1;i <= n*m;i++)
    {
        for(int j = 1;j <= n*m;j++)
        {
            if(s[j] < s[j+1])
            {
                int w = s[j];
                s[j] = s[j+1];
                s[j+1] = w;
            }
        }
    }
    int o = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            a[i][j] = s[o];
            o++;
        }
        i++;
        for(int j = m;j >= 1;j--)
        {
            a[i][j] = s[o];
            o++;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] == u)
            {
                cout << i << " " << j;
                break;
            }
        }
    }
    return 0;
}
