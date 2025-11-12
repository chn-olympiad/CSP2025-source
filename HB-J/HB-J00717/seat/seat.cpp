#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
int r;
int mc = 0;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    r = a[1];
    for(int i = 1; i <= n * m; i++)
    {
        if(a[i] > r)
        {
            mc++;
        }
    }
    int l = mc / n + 1;
    int h = mc % m + 1;
    if(l % 2 == 0)
    {
        h = (n - h + 1);
    }
    cout << l << ' ' << h;
    return 0;
}