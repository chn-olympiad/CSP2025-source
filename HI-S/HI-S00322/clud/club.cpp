#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
    int t,n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<vector<int>> a(n, vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        int f=n/2;
        vector<vector<vector<int>>> dp(n + 1);
            vector<vector<int>>(f+1);
                vector<int>(f+1-1);
        dp[0][0][0]=0;
        for (int i=0;i<n;i++){
            for(int x=0;x<=min(i,f);x++) {
                for(int y=0;y<=min(i-x,f);y++){
                    if(dp[i][x][y]==-1) continue;
                    int z=i-x-y;
                    if(z >f) continue;
                    if(x+1<=f){
                        dp[i+1][x+1][y]=max(dp[i+1][x+1][y],dp[i][x][y]+a[i][0]);
                    }
                    if (y+1<=f){
                        dp[i+1][x][y+1]=max(dp[i+1][x][y+1],dp[i][x][y]+a[i][1]);
                    }
                    if (z+1<=f){
                        dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][x][y]+a[i][2]);
                    }
                }
            }
        }
        int ans=0;
        int num=n;
        for(int x=0;x<=f;x++){
            for(int y=0;y<=f;y++){
                int z=num-x-y;
                if(z>=0&&z<=limit&&dp[n][x][y]!=-1){
                    ans=max(ans,dp[n][x][y]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
