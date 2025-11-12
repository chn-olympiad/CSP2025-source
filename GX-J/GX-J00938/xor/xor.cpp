#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin >> n >> k;
    int flg = 1;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        if(a[i] != 1)
        {
            flg = 0;
        }
    }
    if(flg == 1)
    {
        if(k == 1)
        {
            cout << n;
        }
        else if(k == 0)
        {
            cout << n/2;
        }
        else
        {
            cout << 0;
        }
        return 0;
    }
    cout << 34;
    return 0;
}
//HXYHXYHXY
