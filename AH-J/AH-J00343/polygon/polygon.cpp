#include <bits/stdc++.h>
#define M 998244353
using namespace std;
vector<long long> a;
vector<long long> tmpdp,dp;
long long n,ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    a.resize(n);
    for(auto &p:a) cin>>p;
    sort(a.begin(),a.end());
    dp.resize(a.back()+2,0);
    tmpdp.resize(a.back()+2,0);
    for(auto &i:a){
        for(long long j=i+1;j<dp.size();j++)
            ans=(ans+dp[j])%M;
        for(long long j=dp.size()-1;j>=dp.size()-1-i;j--)
            dp.back()=(dp.back()+dp[j]+tmpdp[j])%M;
        for(long long j=dp.size()-2;j>=i;j--)
            dp[j]=(dp[j]+dp[j-i]+tmpdp[j-i])%M;
        tmpdp[i]++;
    }
    cout<<ans;
    return 0;
}
