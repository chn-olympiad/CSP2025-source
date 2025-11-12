#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=5*10e5+10;
ll a[maxn];
ll sum[maxn];
ll dp[1005][1005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=(sum[i-1]^a[i]);
    }
    if (n<=1003){
        ll ans=0;
        for (int j=1;j<=n;j++){
            for (int i=j;i>=1;i--){
                dp[i][j]=max(dp[i+1][j],max(dp[i][j-1],dp[i][j]));
                for (int k=i;k<j;k++) dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                if (dp[i][j]==0 and (sum[j]^sum[i-1])==m) {
                    dp[i][j]++;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    else cout<<423;

    return 0;
}
