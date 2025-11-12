#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x=0,k=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')k=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*k;
}
int n,t,dp[100003][3],sz[100003][3][3],a[10003][3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();memset(dp,0,sizeof dp);memset(sz,0,sizeof sz);
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        dp[1][0]=a[1][0];dp[1][1]=a[1][1];dp[1][2]=a[1][2];
        sz[1][0][0]=1;sz[1][1][1]=1;sz[1][2][2]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<3;j++){
                int maxn=0,id=0;
                for(int k=0;k<3;k++){
                    if(sz[i-1][k][j]+1<=n/2){
                        if(maxn<dp[i-1][k]){maxn=dp[i-1][k];id=k;}
                    }
                }
                //if(id!=0){
                    dp[i][j]=dp[i-1][id]+a[i][j];
                    sz[i][j][0]=sz[i-1][id][0];
                    sz[i][j][1]=sz[i-1][id][1];
                    sz[i][j][2]=sz[i-1][id][2];sz[i][j][j]++;
                //}
            }
        }
        cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<"\n";
    }
    return 0;
}
