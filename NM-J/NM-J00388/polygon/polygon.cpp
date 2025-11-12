#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,a[5010];
long long dp[5010][5010],s[5010],md[5010][5010],maxn,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        s[i] = s[i-1]+a[i];
        maxn = max(maxn,a[i]);
    }
    if (n<3){
        cout<<0;
        return 0;
    }
    if (maxn<=1){
        for (int l = 3;l<=n;l++){
            for (int i=1;i<=n-l;i++){
                for (int j=1;j<=n-i-l+2;j++){
                    cnt+=j;
                }
            }
        }
        cout<<cnt;
        return 0;
    }
    if (n == 3){
        if (s[3]>2*maxn) cout<<1;
        else cout<<0;
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<3;j++){
            dp[i][i+j] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            for (int k=i;k<=j;k++){
                md[i][j] = max(md[i][j],max(md[i][k],md[k][j]));
            }

        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (s[j]-s[i-1]>2*md[i][j]){
                dp[i][j] = (max(dp[i][j],dp[i][j-1]+1))%mod;
            }
            else dp[i][j] = dp[i][j-1];
        }
    }
    cout<<dp[1][n]%mod<<endl;
    return 0;
}
