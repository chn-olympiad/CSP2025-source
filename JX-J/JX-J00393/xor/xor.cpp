#include<bits/stdc++.h>
using namespace std;
int a[500050],b[500050],c[500050],dp[500050];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    if(b[1]==m){
        dp[1]=1;
    }
    c[b[1]]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1];
        if(c[b[i]^m]!=0||(b[i]^m)==0){
            dp[i]=max(dp[i],dp[c[b[i]^m]]+1);
        }
        c[b[i]]=i;
    }
    cout<<dp[n];
    return 0;
}
