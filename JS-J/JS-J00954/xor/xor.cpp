#include<bits/stdc++.h>
using namespace std;
long long dp[500001],n,k,a[500001];
int main(){
    ios::sync_with_stdio(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        int yhh=0;
        for(int j=i;j>0;j--){
            yhh^=a[j];
            if(dp[j-1]+1<=dp[i])break;
            if(yhh==k){dp[i]=dp[j-1]+1;}
        }
    }
    cout<<dp[n];
    return 0;
    }
