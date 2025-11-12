#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[100001][3]={},dp[201][101][101][101]={};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i=1;i<=n;i++){
            for(int k=0;k<=n/2;k++){
            for(int l=0;l<=n/2;l++){
            for(int j=0;j<=n/2;j++){
                int j1,j2,j3;
                j1=j2=j3=0;
                if(j!=0)
                    j1=dp[i-1][j-1][l][k]+a[i][0];
                if(l!=0){
                    j2=dp[i-1][j][l-1][k]+a[i][1];
                }
                if(k!=0)
                    j3=dp[i-1][j][l][k-1]+a[i][2];
                dp[i][j][l][k]=max(j1,max(j2,j3));

            }
            }
            }
        }
        cout<<dp[n][n/2][n/2][n/2]<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
