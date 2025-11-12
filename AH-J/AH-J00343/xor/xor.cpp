#include <bits/stdc++.h>
using namespace std;
vector<int> a,dp;
unordered_map<int,int> m;
int n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    a.resize(n); dp.resize(n+1);
    for(auto &p:a) cin>>p;
    dp[0]=0; m[0]=0;
    for(int i=1,sum=0;i<=n;i++){
        m[sum]=i;sum^=a[i-1];
        dp[i]=dp[i-1];
        if(m.count(sum^k))
            dp[i]=max(dp[i],dp[m[sum^k]]+1);
    }
    cout<<dp[n];
    return 0;
}
