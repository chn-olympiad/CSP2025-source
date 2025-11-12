#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,x[1005][1005],dp[1005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=i;j++)x[j][i]=x[j][i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int j=1;j<=i;j++)
            if(x[j][i]==m)dp[i]=max(dp[i],dp[j-1]+1);
    }
    cout<<dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
