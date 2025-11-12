#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;

long long a[4][N], dp[N], cc[4], dpi;
int t, n, s;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        memset(cc, 0, sizeof(cc));
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        s = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[1][i] >> a[2][i] >> a[3][i];
        }
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            dpi = 0;
            if(cc[1] >= n / 2)
            {

                 for(int j = 2; j <= 3; j++)
                {
                    dp[i] = max(dp[i - 1] + a[j][i], dp[i]);
                    if(dp[i] >= dpi)
                    {
                        s = j;
                        dpi = dp[i];
                    }
                }
            }
            else if(cc[2] >= n / 2)
            {

                dp[i] = max(dp[i - 1] + a[1][i], dp[i]);
                if(dp[i] > dpi)
                {
                    s = 1;
                    dpi = dp[i];
                }
                dp[i] = max(dp[i - 1] + a[3][i], dp[i]);
                if(dp[i] > dpi)
                {
                    s = 3;
                    dpi = dp[i];
                }
            }
            else if(cc[3] >= n / 2)
            {
                for(int j = 1; j <= 2; j++)
                {
                    dp[i] = max(dp[i - 1] + a[j][i], dp[i]);
                    if(dp[i] > dpi)
                    {
                        s = j;
                        dpi = dp[i];
                    }
                }
            }
            else
            {
                for(int j = 1; j <= 3; j++)
                {
                    dp[i] = max(dp[i - 1] + a[j][i], dp[i]);
                    if(dp[i] > dpi)
                    {
                        s = j;
                        dpi = dp[i];
                    }
                }
            }
            cc[s]++;
        }
        cout << dp[n] << endl;
    }
    return 0;
}

