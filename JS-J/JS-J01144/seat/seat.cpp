#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int g[105];
int n,m;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> g[1];
    for (int i=2;i<=n*m;i++)
        cin >> g[i];
    int z = g[1];
    sort(g+1,g+n*m+1,cmp);
    int k = 0;
    for (int i=1;i<=n*m;i++)
    {
        if (g[i]==z)
        {
            k = i;
            break;
        }
    }
    int c,r;
    c = ceil(k*1.0/n);
    int w = k%(2*n);
    if (w<=n) r = w;
    else r = 2*n+1-(k%(2*n));
    cout << c << ' ' << r;

    return 0;
}
