#include<bits/stdc++.h>
using namespace std;
int s[20][20];
int w[110];
bool c(int x, int y)
{
    if(x > y)
        return true;
    return false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin >> n >> m;
    for(int i = 1; i <= m * n; i++)
    {
        cin >> w[i];
    }
    int a = w[1];
    sort(w + 1, w + n * m + 1, c);
    for(int i = 1; i <= m; i++)
    {
        if(m % 2 == 1)
        {
            for(int j = 1; j <= n;j++)
            {
                s[i][j] = w[(i - 1) * n + j];
            }
        }
        if(m % 2 == 0)
        {
            for(int j = 1; j <= n; j++)
            {
                s[i][j] = w[n * i + 1 - j];
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[j][i] == a)
            {
                cout << j << ' ' << i;
            }
        }
    }
    return 0;
}
