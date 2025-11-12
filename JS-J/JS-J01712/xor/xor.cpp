#include <bits/stdc++.h>
using namespace std;
int xo[500005],a[500005],dp[500005],pos[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        xo[i]=xo[i-1]^a[i];
        for (int j=pos[i-1]+1;j<=i;j++)
        {
            if ((xo[i]^xo[j-1])==k)
            {
                pos[i]=i;
                dp[i]=dp[i-1]+1;
                break;
            }
            dp[i]=dp[i-1],pos[i]=pos[i-1];
        }
    }
    cout << dp[n];
    return 0;
}
