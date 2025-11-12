#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int n, m, a[N];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n*m; i ++) cin >> a[i];
    int xr = a[1];
    sort(a+1, a+n*m+1, cmp);
    for(int i = 1; i <= n*m; i ++)
    {
        if(a[i] == xr)
        {
            xr = i;
            break;
        }
    }
    if((xr-1)/n % 2) cout << (xr-1)/n+1 << ' ' << n-((xr-1)%n);
    else cout << (xr-1)/n+1 << ' ' << (xr-1)%n+1;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
