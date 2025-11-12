#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[115];
int b[15][15];
int main()
{

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m;
    int s = n * m;
    for(int i = 0; i < s; i++)
    {
        cin >> a[i];
    }

    int t = a[0];
    for(int i = 0; i < s; i++)
    {
        for(int j = i + 1; j < s; j++)
        {
            if(a[i] < a[j]) swap(a[i], a[j]);
        }
    }


    int x = 1;
    int y = 1;
    int cnt = 1;
    b[x][y] = a[0];
    while(cnt < s)
    {
        while(x + 1 <= n && b[x + 1][y] == 0)
        {
            b[++x][y] = a[cnt++];
        }


        if(y + 1 <= m && b[x][y + 1] == 0)
        {
            b[x][++y] = a[cnt++];
        }

        while(x - 1 > 0 && b[x - 1][y] == 0)
        {
            b[--x][y] = a[cnt++];
        }

        if(y + 1 <= m && b[x][y + 1] == 0)
        {
            b[x][++y] = a[cnt++];
        }
    }


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(b[i][j] == t)
            {
                cout << j << ' ' << i;
                return 0;
            }
        }
    }

    return 0;
}
