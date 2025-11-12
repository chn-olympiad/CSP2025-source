#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef unsigned long long ll;
ll f[2*100009];
ll a[2*100009];
ll dp[1009][1009];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            dp[i][i]=1;
        }else{
            dp[i][i]=0;
        }
    }
    for(int len=1;len<n;len++){
        for(int l=1;l<=n-len;l++){
            int r=l+len;
            int t=f[r];
            t^=f[l-1];
            if(t==k){
                dp[l][r]=1;
            }
            for(int m=l;m<r;m++){
                dp[l][r]=max(dp[l][r],dp[l][m]+dp[m+1][r]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
