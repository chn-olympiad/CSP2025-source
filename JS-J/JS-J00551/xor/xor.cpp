#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[500005];
int xor_val[500005];
int dp[500005];

int get_xor(const int &lft, const int &rgh)
{
    return ((xor_val[rgh]) ^ (xor_val[lft - 1]));
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        xor_val[i] = ((xor_val[i - 1]) ^ (arr[i]));
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = i; j >= 1; j--)
        {
            if (get_xor(j, i) == k)
            {
                dp[i] = max(dp[i], dp[j - 1] + 1);
                break;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
