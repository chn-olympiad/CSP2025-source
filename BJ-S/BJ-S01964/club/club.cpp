#include<bits/stdc++.h>
#define int long long
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    it a[100000][100000];
    while(n--){
        int m;
        cin>>m;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                dp[i][j]=a[i][j];
            }
        }
        int a1=0;a2=0,a3=0;
        for(int j=1;j<=m;j++){
            for(int j=1;j<=3;j++){
                if(a1<=m/2&&a2<=m/2&&a3<=m/2){
                    if(j==1)dp[i][j]=max(max(dp[i-1][j]+dp[i][j-1],dp[i][j].dp[i][j-1],dp[i][j],dp[i-2][j],dp[i][j],dp[i][j-2]))
                    else if(j==2)dp[i][j]=max(max(dp[i-1][j]+dp[i][j-1],dp[i][j].dp[i][j-1],dp[i][j],dp[i-2][j],dp[i][j],dp[i][j-2]))
                    else if(j==3)dp[i][j]=max(max(dp[i-1][j]+dp[i][j-1],dp[i][j].dp[i][j-1],dp[i][j],dp[i-2][j],dp[i][j],dp[i][j-2]))

            }
        
        for(int k=1;k<=3*m;k++){
            for(int i=1;i<=n;i++){
        
            }

        }
        


    }
    cout<<dp[i][j]<<endl;
    return 0;
}