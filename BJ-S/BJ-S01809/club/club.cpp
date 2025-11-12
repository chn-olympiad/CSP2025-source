#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005][5],dp[205][105][105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        int n,flag=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[i][j]);
                if(a[i][2]||a[i][3])flag=1;
            }
        }
        if(!flag){
            int x[100005];
            for(int i=1;i<=n;i++)x[i]=a[i][1];
            sort(x+1,x+n+1,cmp);
            ll ans=0;
            for(int i=1;i<=n/2;i++)ans+=x[i];
            printf("%lld\n",ans);
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    int x=i-j-k;
                    if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                    if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                    if(x<=n/2&&x>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
                }
            }
        }
        int ans=0;
        for(int j=1;j<=n/2;j++){
            for(int k=1;k<=n/2;k++){
                int x=n-j-k;
                ans=max(ans,dp[n][j][k]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
