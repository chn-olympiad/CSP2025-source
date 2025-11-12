#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5005];
int sum[505][505];
long long ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    int num = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >>a[i];
        num += a[i];
    }
    if (n < 3)
    {
        cout << 0 << endl;
    }
    if (n == 3)
    {
        if (a[1] + a[2] + a[3] > (2 * max(max(a[1],a[2]),a[3])))
            cout <<1;
        else
            cout << 0;
    }
    if (num == n)
    {
        sum[1][0] = sum[1][1] = 1;
        for (int i = 1; i<=501;i++)
        {
            for (int j = 1;j <= 501;j++)
            {
            	if (i == 1 && j == 1)
            		continue;
                sum[i][j] = (sum[i-1][j] % mod + sum[i-1][j-1] % mod) % mod;
            }
        }
        for (int i = 4;i <= n;i++)
        {
            ans = (ans + sum[n][i]%mod)%mod;
        }
        cout <<ans % mod;
    }
    return 0;
}
