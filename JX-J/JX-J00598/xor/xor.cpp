#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],b[500001],dp[20001][20001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==m){
            dp[i][i]=1;
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i+j<=n;i++){
            if((b[i-1]^b[i+j])==m) dp[i][i+j]=1;
            for(int k=i+1;k<=i+j;k++){
                dp[i][i+j]=max(dp[i][i+j],dp[i][k-1]+dp[k][i+j]);
            }
        }
    }
    cout<<dp[1][n];
}
