#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int dp[5000][5000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=3){
        if(n<=2) cout<<0;
        else{
            if(a[1]+a[2]>a[3]) cout<<1;
            else cout<<0;
        }
        return 0;
    }
    for(int i=-1;i<a[1];i++){
        dp[1][i]=1;
    }
    dp[0][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            for(int sum=0;sum<=a[i]*2;sum++){
                dp[i][sum]+=dp[j][max(0,sum-a[i])];
            }
            //dp[i][a[i]*2]+=dp[j][a[i]];
        }
    }
    //cout<<dp[2][0];
    for(int i=1;i<=n;i++) ans+=dp[i][a[i]*2];
    cout<<(ans-1)%998244353;
    return 0;
}
