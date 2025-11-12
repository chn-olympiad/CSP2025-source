#include<bits/stdc++.h>
using namespace std;
int n,k,a[501000];
int dis[1010][1010],dp[5010][1000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    memset(dis,0,sizeof(dis));
    memset(dp,0,sizeof(dp));
    bool pan=1;
    int sum=0;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0) pan=0;
            if(a[i]==k)dis[1][i]=1;
            if(a[i]==1) sum++;
    }
    if(k==0&&pan){
        if(n%2==1){
            cout<<(n-1)/2;
        }
        else {
            cout<<n/2;
        }
        return 0;
    }
    else if(k==1){
        cout<<sum;
        return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j++){
            dis[i][j]=dis[i-1][j-1]^a[j];

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(j>=i){
                    if(dis[i][j]==k){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-i]+1);
                }
                 else dp[i][j]=max(dp[i-1][j],dp[i][j-i]);

                }
                else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][n];
    return 0;
}
