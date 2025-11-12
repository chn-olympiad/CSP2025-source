#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt = 1;
int a[15][15];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] > a[1][1])
                cnt++;

        }
    int lie, hang;
    if(cnt % n != 0)
        lie = cnt / n + 1;
    else
        lie = cnt / m;
    if(lie % 2 == 1)
    {
        hang = cnt % n;
        if(hang == 0)
            hang = n;
    }
    else
        hang = n - (cnt % n - 1);
    cout << lie << " " << hang;
}