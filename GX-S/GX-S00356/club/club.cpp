#include<bits/stdc++.h>
using namespace std;
int T,a[100100][5],n;
int ans;
int dp[500][500][500];
void dfs(int aa,int b,int c,int k,int ad,int bb,int cc){
    if(k==n+1){
        ans = max(ans,ad+bb+cc);
        return;
    }
    if(aa<n/2) dfs(aa+1,b,c,k+1,ad+a[k][1],bb,cc);
    if(b<n/2) dfs(aa,b+1,c,k+1,ad,bb+a[k][2],cc);
    if(c<n/2) dfs(aa,b,c+1,k+1,ad,bb,cc+a[k][3]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        /*
        for(int i=1;i<=n;i++){
            for(int b=n/2;b>=0;b--){
                for(int c=n/2;c>=0;c--){
                    for(int d=n/2;d>=0;d--){
                        if(b-1>=0&&c-1>=0&&d-1>=0){
                            dp[b][c][d] = max(max(dp[b][c][d],dp[b-1][c][d]+a[i][1]),max(dp[b][c-1][d]+a[i][2],dp[b][c][d-1]+a[i][3]));
                            ans = max(ans,dp[b][c][d]);
                        }
                    }
                }
            }
        }
        */
        dfs(0,0,0,1,0,0,0);
        cout<<ans<<endl;
        ans = 0;
    }
    return 0;
}
