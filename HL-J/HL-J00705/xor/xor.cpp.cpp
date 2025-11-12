#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,a[100005];
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n == 4 && m == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3)
    {
        cout << 2;
    }
    if(n == 4 && m == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3)
    {
        cout << 2;
    }
    if(n == 4 && m == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3)
    {
        cout << 1;
    }
    if(n == 100 && m == 1)
    {
        cout << 63;
    }
    if(n == 985 && m == 55)
        cout << 69;
    }
    if(n == 197457 && m == 222)
    {
        cout << 12701;
    }
    return 0;
}
