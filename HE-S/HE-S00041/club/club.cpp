#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > a(n+5,vector<int>(4));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<int> > dp(n+5,vector<int>(4,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                dp[i][j]=max(dp[i][j],dp[i-1][1]+a[i][j]);
                dp[i][j]=max(dp[i][j],dp[i-1][2]+a[i][j]);
                dp[i][j]=max(dp[i][j],dp[i-1][3]+a[i][j]);
            }
        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
    }
    return 0;
}