#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt,ans,top;
int a[N],dp[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        top=max(a[i],top);
        if(a[i]==1) cnt++;
    }
    for(int i=1;i<=n;i++){
        int x=0;
        dp[i]=dp[i-1];
        for(int j=i;j>=1;j--){
            x=x^a[j];
            if(x==k){
                dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
