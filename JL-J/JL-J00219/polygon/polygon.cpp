#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,ans = 0,sum = 0;
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    int cnt;
    if(n <= 3)
    {
        if(a[0] + a[1] + a[2] > max(a[0],max(a[1],a[2])))
        {
            cout << 1;
            return 0;
        }
    }
    for(cnt = 3;cnt <= 10;cnt ++)
    {
        if(cnt == 3)
        {
            for(int i = 1;i <= n;i ++)
            {
                if(i + 2 <= n)
                {
                    if(a[i] + a[i+1] + a[i+2] > max(a[i],max(a[i+1],a[i+2])) * 2) ans ++;
                }

            }
        }
        else if(cnt == 4)
        {
            for(int i = 1;i <= n;i ++)
            {
                if(i + 3 <= n)
                {
                    if(a[i] + a[i+1] + a[i+2] + a[i+3] > max(max(a[i],max(a[i+1],a[i+2])),a[i+3] ) * 2) ans ++;
                }

            }
        }

    }
    cout << ans % 998244353;
    return 0;
}
