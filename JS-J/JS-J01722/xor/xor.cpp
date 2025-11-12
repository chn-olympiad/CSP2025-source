#include <iostream>
#include <cstdio>
using namespace std;

int arr[500005];
int f[500005];
int dp[500005];
int maxn[500005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int ans = arr[i];
        int j = i;
        while(ans != k)
        {
            j--;
            ans ^= arr[j];

            if(j <= 0)
            {
                break;
            }
        }
        f[i] = j;
        // cout << f[i] << " ";
    }
    // cout << '\n';
    for(int i = 1;i <= n;i++)
    {
        if(f[i] != 0)
        {
            dp[i] = maxn[f[i] - 1] + 1;
        }
        // cout << dp[i] << " ";
        maxn[i] = max(maxn[i - 1],dp[i]);
    }
    /*
    cout << '\n';
    for(int i = 1;i <= n;i++)
    {
        cout << maxn[i] << " ";
    }
    cout << '\n';
    */
    int cnt = 0;
    for(int i = f[n];i <= n;i++)
    {
        cnt = max(cnt,dp[i]);
    }
    cout << cnt;
    return 0;
}
