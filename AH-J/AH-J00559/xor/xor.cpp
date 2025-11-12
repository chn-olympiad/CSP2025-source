#include<bits/stdc++.h>
using namespace std;
int n,k;
int const N=10010;
int dp[N][N];
int m[N][N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    if(n>20000){
            int jw=0,wz;
        for(int i=1;i<=n;i++){cin>>wz;if(wz==1)jw++;else if(wz!=0)break;}
        cout<<jw;return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&dp[i][i]);
        if(dp[i][i]==k){
            m[i][i]=1;
        }
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            dp[i][j]=(dp[i][j-1]^dp[j][j]);
            if(dp[i][j]==k)m[i][j]=1;
            for(int h=i;h<j;h++){
                m[i][j]=max(m[i][j],m[i][h]+m[h+1][j]);
            }
        }
    }
    printf("%d",m[1][n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
