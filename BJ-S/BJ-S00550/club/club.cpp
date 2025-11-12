#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 100010
using namespace std;
int t;
int ca = 0,cb = 0,cc = 0,n;
int a[MAXN],b[MAXN],c[MAXN];
int dp[MAXN][3];//0-a 1-b 2-c
int cnt[MAXN][3][3];
void solve(){
    n = 0;
    ca = 0,cb = 0,cc = 0;
    int ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];
    cnt[1][0][0] = 1;
    cnt[1][1][1] = 1;
    cnt[1][2][2] = 1;
    for(int i = 2;i<=n;i++){
        int m = 0;
        int k = (cnt[i-1][0][0]+1<=n/2)?dp[i-1][0]:0;
        dp[i][0] = max(k,max(dp[i-1][1],dp[i-1][2]))+a[i];
        if(k>dp[i-1][1]&&k>dp[i-1][2]){m = 0;}
        if(dp[i-1][1]>dp[i-1][0]&&dp[i-1][1]>dp[i-1][2]){m = 1;}
        if(dp[i-1][2]>dp[i-1][1]&&dp[i-1][2]>dp[i-1][0]){m = 2;}
                    cnt[i][0][0] = cnt[i-1][m][0]+1;
                    cnt[i][0][1] = cnt[i-1][m][1];
                    cnt[i][0][2] = cnt[i-1][m][2];
        k = (cnt[i-1][0][1]+1<=n/2)?dp[i-1][1]:0;
        dp[i][1] = max(k,max(dp[i-1][0],dp[i-1][2]))+b[i];
        if(dp[i-1][0]>dp[i-1][1]&&dp[i-1][0]>dp[i-1][2]){m = 0;}
        if(k>dp[i-1][0]&&k>dp[i-1][2]){m = 1;}
        if(dp[i-1][2]>dp[i-1][1]&&dp[i-1][2]>dp[i-1][0]){m = 2;}
                    cnt[i][1][0] = cnt[i-1][m][0];
                    cnt[i][1][1] = cnt[i-1][m][1]+1;
                    cnt[i][1][2] = cnt[i-1][m][2];
        k = (cnt[i-1][0][2]+1<=n/2)?dp[i-1][2]:0;
        dp[i][2] = max(k,max(dp[i-1][0],dp[i-1][1]))+c[i];
        if(dp[i-1][0]>dp[i-1][1]&&dp[i-1][0]>dp[i-1][2]){m = 0;}
        if(dp[i-1][1]>dp[i-1][0]&&dp[i-1][1]>dp[i-1][2]){m = 1;}
        if(k>dp[i-1][1]&&k>dp[i-1][0]){m = 2;}
                    cnt[i][2][0] = cnt[i-1][m][0];
                    cnt[i][2][1] = cnt[i-1][m][1];
                    cnt[i][2][2] = cnt[i-1][m][2]+1;
    }
    /*
    for(int i = 1;i<=n;i++){
        printf("%d %d %d\n",dp[i][0],dp[i][1],dp[i][2]);
    }

    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=2;j++){
            printf("%d %d %d || ",cnt[i][j][0],cnt[i][j][1],cnt[i][j][2]);
        }
        printf("\n");
    }
*/
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        solve();
    }
}
