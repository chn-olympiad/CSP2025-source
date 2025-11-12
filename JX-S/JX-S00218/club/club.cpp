#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read(){
    char c=getchar();
    bool flag=false;
    while(!isdigit(c)){
        if(c=='-')flag=true;
        c=getchar();
    }
    int x=0;
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return flag?-x:x;
}
const int N=205;
int T,n,a[N][3],s[N],dp[N][N][N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
        int ans=0;
        n=read();
        for(int i=1;i<=n;i++){
            a[i][0]=read();
            a[i][1]=read();
            a[i][2]=read();
        }
        if(n<=200){
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++)for(int j=(n>>1);j>=0;j--)for(int k=(n>>1);k>=0;k--)for(int o=(n>>1);o>=0;o--){
                dp[j+1][k][o]=max(dp[j+1][k][o],dp[j][k][o]+a[i][0]);
                dp[j][k+1][o]=max(dp[j][k+1][o],dp[j][k][o]+a[i][1]);
                dp[j][k][o+1]=max(dp[j][k][o+1],dp[j][k][o]+a[i][2]);
            }
            for(int i=0;i<=(n>>1);i++)for(int j=0;j<=(n>>1);j++)for(int o=0;o<=(n>>1);o++)ans=max(ans,dp[i][j][o]);
            printf("%d\n",ans);
        }
    }
    return 0;
}
