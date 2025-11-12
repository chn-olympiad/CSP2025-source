#include <bits/stdc++.h>
using namespace std;
int n, m, pts, rk, c, r;
int a[200];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int num  = n * m;
    for(int i = 1; i <= num; i++) cin >> a[i];
    pts = a[1];
    sort(a + 1, a + num + 1);
    for(int i = 1; i <= num; i++)
    {
        if(pts == a[i])
        {
            rk = num - i + 1;
            break;
        }
    }
    c = rk / n;
    if(rk % n != 0) c++;
    cout << c << " ";
    rk = rk - (c - 1) * n;
    if(c % 2 == 0)
    {
        r = n + 1 - rk;
    }
    else
    {
        r = rk;
    }
    cout << r;
    return 0;
}
