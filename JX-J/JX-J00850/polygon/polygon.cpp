#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int vis[5005],a[5005],b[5005],sum[5005],maxx[5005][5005],ans;
/*
int dfs(int p,int cnt,int sum){
    if(cnt >= 3 && cnt <= n){
        int mx = -1;
        for(int i = 1;i<=n;i++){
            if(vis[i] == 1)
                mx = max(b[i],mx);
        }
        if(sum > 2 * mx) ans++;
    }
    if(p == n+1) return ans;
    for(int i = 1;i<=n;i++){
        vis[i] = 1;
        b[p] = a[i];
        dfs(p+1,cnt+1,sum+a[i]);
        vis[i] = 0;


    }
}
*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    }

    if(n < 3){
        cout << 0;
        return 0;
    }
    if(n == 3){
        int mx = -1;
        for(int i = 1;i<=3;i++) mx = max(mx,a[i]);
        if(sum[3] > 2*mx) cout << 1;
        else cout << 0;
    }


    /*
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            for(int k = i;k<=j;k++){
                maxx[i][j] = max(maxx[i][j],a[k]);
            }
        }
    }
    */

    /*
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            cout << maxx[i][j]<<" ";

        }
    }
    */

    /*
    for(int l = 1;l<=n;l++){
        for(int len = 1;len <=n;len++){
            int r = l+len-1;
            for(int k = 1;k<=n;k++){
                if(r <= n){
                    if(sum[r]-sum[l-1] > maxx[l][r]*2 && r-l+1 >= 3){
                        dp[l][r] = (dp[l][k]+dp[k+1][r]+1)%mod;
                    }
                    else{
                        dp[l][r] = (dp[l][k]+dp[k+1][r])%mod;
                    }
                }
            }

        }
    }
    */

    //dfs(1,0,0);
    //cout << ans % mod;
    return 0;
}
