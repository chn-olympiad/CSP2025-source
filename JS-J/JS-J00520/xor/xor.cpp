#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1]={0};
    bool vis[n+1][n+1];
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
            vis[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=a[i];
        if(a[i]==k){
            vis[i][i]=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-1;j++){
            dp[i][j]=int(dp[i][i],dp[i+1][j]);
            if(dp[i][j]==k){
                vis[i][j]=1;
            }
        }
    }
    int t=1,cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=t;j<=n;j++){
            if(vis[i][j]==true){
                t=j+1;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
