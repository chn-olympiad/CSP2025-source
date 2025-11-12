#include <iostream>
using namespace std;
int a[100010];
int dp[100010];
int n,k;
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    a[0]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i==1)
            a[i]=x;
        else
            a[i]=a[i-1]^x;
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int l=i-1;l>=0;l--){
            dp[i]=max(dp[l]+((a[i]^a[l])==k),dp[i]);
        }
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<endl;
    }
    */
    cout<<dp[n];
    return 0;
}
