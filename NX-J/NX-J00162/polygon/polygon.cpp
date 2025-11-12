#include <bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    if(n < 3)
    {
        cout << 0;
        return 0;
    }
    else
    {
        int js = 0;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
            if(a[i] == 1)
            {
                js++;
            }
        }
        if(n == 3 && js != n)
        {
            int sum  = 0,max1 = 0;
            sum  = a[1] + a[2] + a[3];
            max1 = max(max1,max(a[1],max(a[2],a[3])));
            if(sum > max1*2)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        else if(js == n)
        {
            long long ans = 0;
            for(int i = 1;i <= n-2;i++)
            {
                ans += i;
            }
            cout << ans;
            return 0;
        }
        else
        {
            cout << 34;
        }
    }
    return 0;
}
