#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int a[maxn][4],cnt[maxn][4][4];
int dp[maxn][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        int mxn=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                int tmp=0;
                for(int k=1;k<=3;k++){
                    bool flag=0;
                    for(int l=1;l<=n;l++) if(cnt[l][j][k]>=mxn) flag=1;
                    if(flag){
                        continue;
                    }else{
                        if(dp[i][j]<dp[i-1][k]+a[i][j]){
                            tmp=k;
                        }else tmp=j;
                        dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
                    }
                }
                for(int k=1;k<=3;k++) cnt[i][j][k]+=cnt[i-1][tmp][k];
                cnt[i][j][tmp]++;
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<=2;i++) mx=max(mx,dp[n][i]);
        printf("%d\n",mx);
    }
    return 0;
}
