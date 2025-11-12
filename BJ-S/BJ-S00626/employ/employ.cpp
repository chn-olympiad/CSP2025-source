#include <iostream>
using namespace std;
int n,m,c[505],cnt;
long long dp[262205][20],ans;
const long long mod=998244353;
string st;
bool s[505];
long long ad(long long e,long long f){
    if(e+f>mod) return e+f-mod;
    else return e+f;
}
void sv1(){
    dp[0][0]=1;
    for(int i = 1;i < (1<<n);i++){
        cnt=0;
        for(int j = 0;j < n;j++) cnt+=((i>>j)&1);
        for(int j = 0;j <= cnt;j++){
            for(int k = 0;k < n;k++){
                if(!((i>>k)&1)) continue;
                if(!s[cnt]) dp[i][j]=ad(dp[i][j],dp[i^(1<<k)][j]);
                else{
                    if(cnt-j<c[k+1]) dp[i][j]=ad(dp[i][j],dp[i^(1<<k)][j-1]);
                    if(cnt-j-1>=c[k+1]) dp[i][j]=ad(dp[i][j],dp[i^(1<<k)][j]);
                }
            }
            //cout << dp[i][j] << "_";
        }
        //cout << endl;
    }
    for(int i = m;i <= n;i++) ans=ad(ans,dp[(1<<n)-1][i]);
    cout << ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    cin >> st;
    for(int i = 0;i < n;i++) s[i+1]=st[i]-48;
    for(int i = 1;i <= n;i++) cin >> c[i];
    if(m!=n) sv1();
    else{
        for(int i = 1;i <= m;i++){
            if(!s[i] || !c[i]){
                cout << 0;
                return 0;
            }
        }
        ans=1;
        for(int i = 2;i <= n;i++) ans=ans*i%mod;
        cout << ans;
    }
    return 0;
}