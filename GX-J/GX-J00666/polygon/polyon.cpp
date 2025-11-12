#include<bits/stdc++.h>
using namespace std;
int n,a[5010],p;
long long ans=0;
int f(int x){
    int dp[n+10][n+10],num;
    memset(dp,0,sizeof(dp));
    for(int k=n;k<=3;k--){
        int maxn=2*a[k];
        for(int i=n;i<=1;i--){
            for(int j=maxn;j>=1;j--){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i]]);
                if(dp[i][j]==dp[i-1][j-a[i]]) p++;
                if(p==x && dp[i][j]<0) num++;
            }
        }
    }
    return num;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){//mu gun shu liang
        ans+=f(i);
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
