#include <bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005];
int to[500005];
int dp[500005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        to[i]=919191;
        long long ad=a[i];
        if(ad==k){
            to[i]=i;
            continue;
        }
        for(int j=i+1; j<=n; j++){
            ad=ad^a[j];
            if(ad==k){
                to[i]=j;
                break;
            }
        }
    }
    dp[1]=1;
    for(int i=2; i<=n; i++){
        if(to[i]<=n) dp[i]=1;
        if(to[i]>n && i!=n) continue;
        for(int j=i-1; j>=1; j--){
            if(to[j]<i) dp[i]=max(dp[i],dp[j]+(to[i]<=n));
        }
//        cout<<dp[i]<<" ";
    }
    cout<<dp[n]<<"\n";
    return 0;
}
