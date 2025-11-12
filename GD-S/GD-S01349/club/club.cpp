#include<bits/stdc++.h>
using namespace std;
const int maxn=2e2+4;
int T,N;
int w[3][(int)(1e5+5)];
int dp[maxn][maxn/2][maxn/2];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>w[0][i]>>w[1][i]>>w[2][i];
        }
        int ans=0;
        if(N>200){
            sort(w[0]+1,w[0]+N+1);
            for(int i=N;i>N/2;i--) ans+=w[0][i];
            printf("%d\n",ans);
            continue;
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<=(N/2);j++){
                for(int k=0;k<=(N/2);k++){
                    if((i-j-k)>(N/2)) continue;
                    if(j>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+w[0][i]);
                    if(k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+w[1][i]);
                    if((i-j-k-1)>=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+w[2][i]);
                    ans=max(ans,dp[i][j][k]);
                }
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
