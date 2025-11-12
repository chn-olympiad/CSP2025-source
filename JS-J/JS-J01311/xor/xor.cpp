#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005],b[500005],dp[1005][1005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=(b[i-1]^a[i]);
        dp[i][i]=(a[i]==m);
    }
    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=((b[j]^b[i-1])==m);
            for(int k=i;k<j;k++)dp[i][j]=max(dp[i][k]+dp[k+1][j],dp[i][j]);
        }
    }
    cout<<dp[1][n];
    return 0;
}
