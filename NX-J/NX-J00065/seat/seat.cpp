#include <bits/stdc++.h>
using namespace std;
int n, m, mypoint, zw[15][15], fens[105];
bool cmp(int x, int y)
{
    return x >= y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n*m; ++i) cin >> fens[i];
    mypoint = fens[0];
    sort(fens, fens+n*m, cmp);
    int x = 0;
    for (int i = 0, j = 0; i < n*m; ++i, ++j)
    {
        if (i % 2 == 0)
        {
            for (int ii = 0; ii < n; ++ii){
                    zw[ii][j] = fens[x++];
            }
        }
        else
        {
            for (int ii = n-1; ii >= 0; --ii){
                    zw[ii][j] = fens[x++];
            }
        }
    }
    for (int a = 0; a < n; ++a)
    {
        for (int b = 0; b < m; ++b)
        {
            if (mypoint == zw[a][b])
                cout << b+1 << " " << a+1;
        }
    }
    return 0;
}
