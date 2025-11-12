#include<bits/stdc++.h>
using namespace std;
int n,dp[500001];
long long k,a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        for(int j=1;j<=i;j++)
        {
            if((a[i]^a[j-1])==k)
            {
                dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[n];
    return 0;
}
