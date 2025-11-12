#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn=int(2e2)+5;
int a[maxn][4];

int dp[maxn][maxn][maxn];

int read(){
    int igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c<='9' and c>='0'){
        igt=(igt<<3)+(igt<<1)+c-'0';
        c=getchar();
    }
    return igt*sgn;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T=read();
    while(T--){

        memset(a,0,sizeof(a));

        int n=read();
         for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                a[i][j]=read();
            }
        }

        memset(dp,0,sizeof(dp));

        for(int i=0;i*2<=n;i++){
            for(int j=0;j*2<=n and i+j<=n;j++){
                for(int k=0;k*2<=n and i+j+k<=n;k++){
                    if(i>0){
                        dp[i][j][k]=max(dp[i-1][j][k]+a[i+j+k][1],dp[i][j][k]);
                    }
                    if(j>0){
                        dp[i][j][k]=max(dp[i][j-1][k]+a[i+j+k][2],dp[i][j][k]);
                    }
                    if(k>0){
                        dp[i][j][k]=max(dp[i][j][k-1]+a[i+j+k][3],dp[i][j][k]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i*2<=n;i++){
            for(int j=0;j*2<=n and i+j<=n;j++){
                for(int k=0;k*2<=n and i+j+k<=n;k++){
                    ans=max(dp[i][j][k],ans);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
