#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[600000];
int sum;
int dp[20010][20010];
bool cq[600000];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        cq[i] = 1;
    }
    for (int i = 0; i <= n; i ++)
    {
        for (int j = 1; i+j <= n; j ++)
        {
            if (i == 0)
            {
                dp[j][j] = a[j];
            }
            else
            {
                dp[j][i+j] = dp[j][i+j-1] ^ dp[j+1][i+j];
            }
            bool flag = true;
            for (int x = j; x <= i+j; x ++)
            {
                if (!cq[x])
                {
                    flag = false;
                    break;
                }
            }
            if (dp[j][i+j] == k && flag)
            {
                sum ++;
                for (int x = j; x <= i+j; x ++) cq[x] = 0;
            }
        }
    }
    cout << sum << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
