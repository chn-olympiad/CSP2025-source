#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, b, x, w = 1, r, c;
    cin >> n >> b;
    x = n * b;
    int m[x];
    for(int i;i <= x;i++)
    {
        cin >> m[i];
        if(m[1] < m[i])
        {
            w++;
        }
    }
    h = w % n;
    if(r == 0)
    {
        r++;
        c = w / n;
    }
    else
    {
        c = w / n;
        c++;
    }
    cout << c << r;
    return 0;
}
