#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+77;
int n,k;
int a[N];
long long dp[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int len = i;len>=1;len--){
            int temp = a[i-len+1];
            for(int j = i-len+2;j <= i;j++){
                temp^=a[j];
            }
            if(temp == k){
                dp[i] = max(dp[i-len]+1,dp[i]);
            }
            else{
                dp[i] = max(dp[i],dp[i-1]);
            }
        }
    }
    cout<<dp[n];
    return 0;
}
