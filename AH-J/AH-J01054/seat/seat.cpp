#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",in);
    freopen("seat.out","w",out)
    int n,m;
    cin >> n >> m;
    int a[30][30];
    for(int i = 1; i<=n; i++)
    {
         for(int j = 1; j<= m; j++)
         {
             cin >> a[i][j];
         }
    }
    if (n = 1)
    {
        if(m = 1)
        {
            cout << a[1][1];
        }
    }
    return 0;
}
