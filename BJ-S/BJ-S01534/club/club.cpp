#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,re=0,is=1;
        cin>>n;
        int a[n+1][4],dp[n/2+1][n/2+1][n/2+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            if(!(a[i][2]==0&&a[i][3]==0))
                is=0;
        if(is){
            int b[n+1];
            for(int i=1;i<=n;i++)
                b[i]=a[i][1];
            sort(b+1,b+n+1);
            for(int i=n;i>n/2;i--){
                re+=b[i];
            }
            cout<<re<<endl;
            break;
        }
        for(int i=0;i<=n/2;i++)
            for(int j=0;j<=n/2;j++)
                for(int k=0;k<=n/2;k++)
                    dp[i][j][k]=0;
        for(int i=0;i<=n/2;i++)
            for(int j=0;j<=n/2;j++)
                for(int k=0;k<=n/2;k++){
                    if((!i)&&(!j)&&(!k))
                        continue;
                    if(i+j+k<=n){
                        if(i)
                            dp[i][j][k]=max(dp[i-1][j][k]+a[i+j+k][1],dp[i][j][k]);
                        if(j)
                            dp[i][j][k]=max(dp[i][j-1][k]+a[i+j+k][2],dp[i][j][k]);
                        if(k)
                            dp[i][j][k]=max(dp[i][j][k-1]+a[i+j+k][3],dp[i][j][k]);
                        if(i+j+k==n){
                            re=max(re,dp[i][j][k]);
                        }
                    }
                }
        cout<<re<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
