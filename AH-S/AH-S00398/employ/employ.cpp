#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int c[500],cmd[500],dp[262144][19];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        cmd[i]=ch-'0';
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    dp[0][0]=1;
    if(n<=18){
        for(int i=0;i<(1<<n);i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    cnt++;
                }
            }
            for(int j=0;j<n;j++){
                if(!(i&(1<<j))){
                    for(int k=0;k<=cnt;k++){
                        if(cmd[cnt]==0  ||  cnt-k>=c[j]){
                            dp[i+(1<<j)][k]+=dp[i][k];
                            dp[i+(1<<j)][k]%=mod;
                        }
                        else{
                            dp[i+(1<<j)][k+1]+=dp[i][k];
                            dp[i+(1<<j)][k+1]%=mod;
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++){
            ans+=dp[(1<<n)-1][i];
            ans%=mod;
        }
        printf("%d",ans);
    }
    return 0;
}
