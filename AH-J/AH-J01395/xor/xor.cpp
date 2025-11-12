#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N=5e5+5;
int a[N];
int x[N]={0};
int dp[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            x[i]=x[i-1]^a[i];
        }else x[i]=a[i];
        if(a[i]==k){
            dp[i]++;
        }
    }
    int cnt=0;

    for(int i=2;i<=n;i++){

        dp[i]=max(dp[i],dp[i-1]);
        for(int j=1;j<i;j++){
            int y=x[i]^x[j-1];
             if(y==k){
                dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
    }cout<<dp[n];
    return 0;
}
