#include<bits/stdc++.h>
using namespace std;
int n,k,t1,t2,ans,a[500005],dp[500005];
bool h[500005][21];
bool checkbit(int n,int i){
    if(n&(1<<i))return 1;
    return 0;
}
bool check(int l,int r){
    for(int i=0;i<20;i++){
        if((h[l-1][i]^h[r][i])==checkbit(k,i))continue;
        else return 0;
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<20;j++){
            h[i][j]=h[i-1][j];
            if(checkbit(a[i],j))h[i][j]^=1;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        for(int j=i;dp[j]==dp[i]&&j>=1;j--){
            dp[i]=max(dp[i],dp[j-1]+check(j,i));
        }
    }
    printf("%d",dp[n]);
    return 0;
}
