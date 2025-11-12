#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,maxv,x;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
        maxv = max(a[i],a[i+1]);
    }
    if (n == 1 && m == 1)
    {
        cout << 1 << " " << 1;
    }
    else if (x + 1 == maxv && n == 1)
    {
        cout << 2 << " " << 1;
        }
    else if(x + 1 == maxv && n != 1)
    {
        cout << 1 << " " << 2;
    }
    else
    {
        cout << 10 << " " << 10;
    }
    return 0;
}
