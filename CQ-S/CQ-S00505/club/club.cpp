#include <bits/stdc++.h>

using namespace std;

int T,n;
int a[202][5];
int dp[2][102][102][102],ans;
int b[100002];

void _solution_200();

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n<=200)  _solution_200();
        else{
            for(int i=1;i<=n;i++)   scanf("%d %d %d",&b[i],&a[i][1],&a[i][1]);
            ans=0;
            sort(b+1,b+n+1);
            for(int i=(n>>1)+1;i<=n;i++)  ans+=b[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}

void _solution_200(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
            scanf("%d",&a[i][j]);
    memset(dp,0,sizeof dp);ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=(n>>1);j++){
            for(int k=0;k<=(n>>1);k++){
                int l=i-j-k-1;
                if(l>(n>>1))  continue;
                if(l<0) break;
                if(j<(n>>1))    dp[i%2][j+1][k][l]=max(dp[i%2][j+1][k][l],dp[(i+1)%2][j][k][l]+a[i][1]);
                if(k<(n>>1))    dp[i%2][j][k+1][l]=max(dp[i%2][j][k+1][l],dp[(i+1)%2][j][k][l]+a[i][2]);
                if(l<(n>>1))    dp[i%2][j][k][l+1]=max(dp[i%2][j][k][l+1],dp[(i+1)%2][j][k][l]+a[i][3]);
            }
        }
    }
    for(int j=0;j<=(n>>1);j++)
        for(int k=0;k<=(n>>1);k++){
            int l=n-j-k;
            if(l<0) break;
            ans=max(ans,dp[n%2][j][k][l]);
        }
    printf("%d\n",ans);
}