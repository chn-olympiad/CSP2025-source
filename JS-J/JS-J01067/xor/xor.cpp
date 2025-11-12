#include <bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n,k,a[N],dp[N],sum[N];
unordered_map<int,bool>vis;
unordered_map<int,int>mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum[i]=(sum[i-1]^a[i]);
    }
    mp[k]=0,vis[k]=true;
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1];
        if(vis[sum[i]]){
            dp[i]=max(dp[i],dp[mp[sum[i]]]+1);
        }
        mp[sum[i]^k]=i,vis[sum[i]^k]=true;
    }
    cout<<dp[n];
    return 0;
}
