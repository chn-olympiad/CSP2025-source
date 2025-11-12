#include<bits/stdc++.h>
using namespace std;
int T;
int n,dp[31][31][31][31];
struct stu{
    int a1,a2,a3;
}a[101];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        for(int i=1;i<=n;i++){
            for(int j=n;j>=1;j--){
                for(int k=n;k>=1;k--){
                    for(int z=n;z>=1;z--){
                        dp[i][j][k][z]=max(dp[i-1][j-1][k][z]+a[i].a1,
                                           max(dp[i-1][j][k-1][z]+a[i].a2,max(dp[i-1][j][k][z],dp[i-1][j][k][z-1]+a[i].a3)));
                    }
                }
            }
        }
        cout<<dp[n][n/2][n/2][n/2]<<'\n';
    }
    return 0;

}
