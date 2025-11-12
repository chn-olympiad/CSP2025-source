#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i],dp[i-1]);
        int num=a[i];
        if(num==k){
            dp[i]=max(dp[i],dp[i-1]+1);
            continue;
        }
        for(int j=i+1;j<=n;j++){
            num=int(num|a[j])-int(num&a[j]);
            if(num==k){
                dp[j]=max(dp[j],dp[i-1]+1);
                break;
            }
        }
    }
    cout<<dp[n];
    return 0;
}
