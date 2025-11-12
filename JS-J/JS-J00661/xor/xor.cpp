#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N],c[N],dp[N];
void solve(){
    if(k==1){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                cnt++;
        cout<<cnt;
    }
    else{
        int cnt=0,w=0;
        for(int i=1;i<=n;i++)
            if(a[i]==0)
                cnt++;
        for(int i=1;i<=n;i++){
            if(a[i]==1)
                w++;
            if(w==2){
                cnt++;
                w=0;
            }
        }
        cout<<cnt;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool flag=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)
            flag=0;
        c[i]=(c[i-1]^a[i]);
    }
    if(n>1000&&flag&&k<2){
        solve();
        return 0;
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int j=i;j>=1;j--){
            if((c[i]^c[j-1])==k){
                dp[i]=max(dp[i],dp[j-1]+1);
                break;
            }
        }
        //cout<<dp[i]<<"\n";
    }
    cout<<dp[n];
    return 0;
}
