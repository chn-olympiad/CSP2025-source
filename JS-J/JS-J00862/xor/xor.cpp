#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n+5);
    for(long long i=0;i<n;++i){
        cin>>a[i];
    }
    long long cnt=0;
    vector<vector<int> > g(n+5);
    for(int i=0;i<n;++i){
        cnt=0;
        for(int j=i;j<n;++j){
            cnt^=a[j];
            if(cnt==k){
                g[j].push_back(i);
            }
        }
    }
    vector<long long> dp(n+5);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<(int)g[i-1].size();++j){
            dp[i]=max(dp[i],dp[g[i-1][j]]+1);
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n]<<endl;
    return 0;
}