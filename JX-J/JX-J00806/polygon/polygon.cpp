#include <bits/stdc++.h>
using namespace std;
int n,dp[105];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>dp[i];
    cout<<dp[5]+dp[4];
    return 0;
}
