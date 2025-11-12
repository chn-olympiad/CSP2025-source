#include<bits/stdc++.h>
#define N 20
#define ll long long
using namespace std;

string s;
int n,m,c[N],dp[1<<N][N];
int popcnt(int x){
    if(!x)return x;
    return popcnt(x>>1)+(x&1);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<=popcnt(i);j++){
            for(int k=1;k<=n;k++){
                //这一次招的是k
                //k有没有拒绝？
                //bzd
                //刷表
                if(i&(1<<k-1))continue;
                //新人来了
                if(c[k]<=j||s[popcnt(i)]=='0'){
                    dp[i|(1<<k-1)][j+1]=dp[i|(1<<k-1)][j+1]+1ll*dp[i][j];//新人炸了
                    dp[i|(1<<k-1)][j+1]%=998244353;
                }
                else {
                    dp[i|(1<<k-1)][j]=dp[i|(1<<k-1)][j]+1ll*dp[i][j];
                    dp[i|(1<<k-1)][j]%=998244353;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(n-i>=m){
            ans=(ans+dp[(1<<n)-1][i])%998244353;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/*
1 4 6
2 3 7
4 2 5
4 3 4
*/