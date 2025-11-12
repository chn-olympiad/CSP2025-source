#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int n,a[5001],dp[505][50005];
int c[5005][5005];

void init(){
    c[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n>500){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        init();
        int ans=0;
        for(int i=3;i<=n;i++){
            ans=(ans+c[n+1][i+1])%mod;
        }
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=50000;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i])
                dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
    }
    int ans=0;
    for(int i=3;i<=n;i++){
        for(int j=a[i]+1;j<=50000;j++){
            ans=(ans+dp[i-1][j])%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}
