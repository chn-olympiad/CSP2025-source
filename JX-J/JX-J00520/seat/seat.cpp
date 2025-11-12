#include<bits/stdc++.h>
using namespace std;
int n, m, a, x, nu = 1;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m >> a;
    for (int i = 1; i < n*m; i++)
    {
        cin >> x;
        if (x > a) nu++;
    }
    int c = nu%m;
    int d = nu/m;
    if (c == 0)
    {
        cout << d << " ";
        if (d&1) cout << m;
        else cout << 1;
    }
    else
    {
        cout << d+1 << " ";
        if (d&1) cout << m-c+1;
        else cout << c;
    }
}
