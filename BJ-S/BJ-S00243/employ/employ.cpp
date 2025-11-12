#include <bits/stdc++.h>
using namespace std;
#define M 998244353
int a[510],dp[(1<<18)][20],ans[510],C[510][510];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,sum=0; cin>>n>>m;
    string s; cin>>s;
    for (int i=1; i<=n; i++) cin>>a[i];
    dp[0][0]=1;
    for (int i=0; i<(1<<n); i++){
            int cnt=0;
        for (int j=1; j<=n; j++) if (i&(1<<j-1))cnt++;
        for (int j=0; j<=n; j++){
            for (int k=1; k<=n; k++){
                if (i&(1<<k-1)) continue;
                if (s[cnt]=='0'||a[k]<=cnt-j)dp[i+(1<<k-1)][j]=(dp[i+(1<<k-1)][j]+dp[i][j])%M;
                else dp[i+(1<<k-1)][j+1]=(dp[i+(1<<k-1)][j+1]+dp[i][j])%M;
            }
        }
    }
    int ans=0;
    for (int i=m; i<=n; i++){
        ans=(ans+dp[(1<<n)-1][i])%M;
    }
    cout<<ans;
}
