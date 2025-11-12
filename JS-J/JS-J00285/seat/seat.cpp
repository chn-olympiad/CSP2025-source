#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[121],c,r;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    int pos = a[1];
    sort(a + 1, a + n*m + 1,cmp);
    int f = 0;
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == pos) f = i;
    }
    int emy = f / n;
    if (f % n != 0) emy ++;
    c = emy;
    if (c % 2 == 1)
    {
        if (f % n == 0) r = n;
        else r = (f % n);
    }
    if (c % 2 == 0)
    {
        if (f % n == 0) r = 1;
        else r = n - (f % n) + 1;
    }
    if (r == 0) r = n;
    cout << c << " " << r << '\n';
    return 0;
}
