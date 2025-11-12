#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
    int lk[4];
}a[N];
int n;
int dp[N][4][5];
void tfo(int x,int y){
    cout<<x<<" "<<y<<" "<<'\n';
    for(int i=0;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=4;k++){
                cout<<dp[i][j][k]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
}
void tfo2(int x,int y,int z){
    cout<<x<<" "<<y<<" "<<z<<'\n';
    for(int i=1;i<=3;i++){
        for(int j=1;j<=4;j++){
            cout<<dp[x][i][j]<<" ";
        }
        cout<<'\n';
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i].lk[j];
        }
    }
    /*
    for(int i=0;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=4;k++){
                dp[i][j][k]=0;
            }
        }
    }
    */
    memset(dp,0,sizeof dp);
    /*
    for(int i=0;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=4;k++){
                cout<<dp[i][j][k]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            int temp=-1;
            for(int k=1;k<=3;k++){
                if(dp[i-1][k][j]*2<n){
                    if(dp[i-1][k][4]+a[i].lk[j]>=dp[i][j][4]){
                        /*
                        for(int l=1;l<=3;l++){
                            if(l==j){
                                dp[i][j][l]=dp[i-1][k][l]+1;
                            }else{
                                dp[i][j][l]=dp[i-1][k][l];
                            }
                        }
                        */
                        temp=k;
                    }
                }else{
                    continue;
                }
            }
            if(temp!=-1){
                for(int l=1;l<=3;l++){
                    if(l==j){
                        dp[i][j][l]=dp[i-1][temp][l]+1;
                    }else{
                        dp[i][j][l]=dp[i-1][temp][l];
                    }
                    //tfo2(i,j,temp);
                }
            }
            dp[i][j][4]=dp[i-1][temp][4]+a[i].lk[j];
            //cout<<i<<" "<<j<<" "<<temp<<" "<<dp[i][j][4]<<" "<<dp[i-1][temp][j]<<'\n';

        }
    }
    cout<<max(dp[n][1][4],max(dp[n][2][4],dp[n][3][4]))<<'\n';
    /*
    for(int i=0;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=4;k++){
                cout<<dp[i][j][k]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    */
    //cout<<dp[0][3][1];
    //cout<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
