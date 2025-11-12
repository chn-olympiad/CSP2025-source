#include <bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int a[N][4];
int dp[N][N];//dp[i][j][k](滚动数组省略i):前i个中选择j个到1社团，k个到2社团的最大满意度
void solve(){
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j>=0;j--){
            for(int k = i-j;k>=0;k--){
                dp[j][k]=max(max((i-j-k>=1)?(dp[j][k]+a[i][3]):(int(-1e9)),(k>=1)?(dp[j][k-1]+a[i][2]):(int(-1e9))),(j>=1)?(dp[j-1][k]+a[i][1]):(int(-1e9)));
            }
        }
        //for(int j = 0;j<=i;j++){
        //    for(int k = 0;k<=i-j;k++){
        //        cout<<j<<k<<" "<<dp[j][k]<<"  ";
        //    }cout<<endl;
        //}
    }
    int maxn=-1;
    for(int i = 0;i<=n/2;i++){
        for(int j = n/2-i;j<=n/2;j++){
            maxn=max(maxn,dp[i][j]);
        }
    }
    cout<<maxn<<endl;
    for(int i = 0;i<=n;i++){
        a[i][1]=a[i][2]=a[i][3]=0;
        for(int j = 0;j<=n;j++){
            dp[i][j]=0;
        }
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
