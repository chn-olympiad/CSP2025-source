#include<bits/stdc++.h>
using namespace std;
int dp[500005],lst[500005],w[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,a,sum;
    cin>>n>>k;
    sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a;
        sum = sum^a;
        if(w[sum^k]){
            lst[i] = w[sum^k];
        }else if(sum == k){
            lst[i] = 0;
        }else{
            lst[i] = -1;
        }
        w[sum] = i;
    }
    for(int i = 1;i<=n;i++){
        if(lst[i]>=0){
            dp[i] = max(dp[i-1],dp[lst[i]]+1);
        }else{
            dp[i] = dp[i-1];
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
