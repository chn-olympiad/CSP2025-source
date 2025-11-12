#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5+3999;
int p[N][5];
int t,n;
int m;
int dp[N][4][5];


void solve(){
    //cout<<"\n\n\n";

    dp[0][0][4]=p[0][0];
    dp[0][0][0]=1;
    dp[0][1][4]=p[0][1];
    dp[0][1][1]=1;
    dp[0][2][4]=p[0][2];
    dp[0][2][2]=1;
    dp[0][3][4]=0;
    //for(int i=0;i<n;i++)dp[0][i][3]=-n;
    //for(int f=0;f<4;f++)printf("dp[%d][%d].v = %d    (%d,%d,%d,%d)\n",0,f,dp[0][f][4],dp[0][f][0],dp[0][f][1],dp[0][f][2],dp[0][f][3]);
    //printf("________________________________\n");
    for(int i=1;i<n;i++){
        for(int pr=0;pr<4;pr++){
            int better=3,rk=1;
            for(int k=1;i-k>=0;k++){
                for(int f=0;f<4;f++){
                if(dp[i-k][f][pr]<m){
                    if(dp[i-k][f][4]>dp[i-rk][better][4]){
                            better=f;rk=k;
                    }
                }
                }
            }

                //printf("[%d]",better);
                for(int f=0;f<4;f++){
                    dp[i][pr][f]=dp[i-rk][better][f];
                }
                dp[i][pr][4]+=dp[i-rk][better][4];
                if(pr!=3){
                        dp[i][pr][pr]++;
                    dp[i][pr][4]+=p[i][pr];
                }

        //printf("dp[%d][%d].v=%d    (%d,%d,%d,%d)\n",i,pr,dp[i][pr][4],dp[i][pr][0],dp[i][pr][1],dp[i][pr][2],dp[i][pr][3]);
        }
        //printf("________________________________\n");


    }


}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%d",&n);
        m=n/2;
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++)
                scanf("%d",&p[i][j]);
        }solve();
        n--;
        int ans=max(max(max(dp[n][0][4],dp[n][1][4]),dp[n][2][4]),dp[n][3][4]);

        printf("%d\n",ans);
    }












    return 0;
}
