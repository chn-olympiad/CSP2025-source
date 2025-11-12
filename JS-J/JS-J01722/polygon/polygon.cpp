#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[5005];
int s[5005][8];
int dp[3000005];
int f[3000005];
const int mod = 998244353;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int maxn = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
        maxn = max(maxn,arr[i]);
    }
    sort(arr + 1,arr + 1 + n);
    if(maxn <= 1)
    {
        int ans = 1;
        s[1][1] = 1;
        for(int i = 2;i <= n + 1;i++)
        {
            s[i][1] = 1;
            s[i][2] = (s[i - 1][1] + s[i - 1][2]) % mod;
            s[i][3] = (s[i - 1][2] + s[i - 1][3]) % mod;
            s[i][4] = (s[i - 1][3] + s[i - 1][4]) % mod;
        }
        cout << s[n + 1][4];
        return 0;
    }
    dp[0] = 1;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = n * maxn;j >= 1;j--)
        {
            if(j >= arr[i])
            {
                dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
                if(j > 2 * arr[i])
                {
                    cnt = (dp[j - arr[i]] + cnt) % mod;
                }
            }
        }
        /*
        for(int j = 0;j <= n;j++)
        {

            cout << dp[j] << " ";
        }
        cout << '\n';
        */
    }
    cout << cnt;
    return 0;
}
