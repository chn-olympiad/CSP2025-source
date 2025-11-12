#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int n,m;
int num[N];
int c[N];
int dp[1<<18][20];
const int mod = 998244353;
void add(int &x,int y){
    x = (x+y>=mod?x+y-mod:x+y);
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    bool fl = 1;
    for(int i = 1;i <= n;i++){
        char c;
        cin >> c;
        num[i] = c-'0';
        if(num[i] == 0){
            fl = 0;
        }
    }
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }
    if(n <= 18){
        dp[0][0] = 1;
        for(int i = 0;i < (1<<n);i++){
            int cn = __builtin_popcount(i);
            for(int j = 0;j <= cn;j++){
                for(int k = 0;k < n;k++){
                    if((i>>k)&1){
                        continue;
                    }
                    int tj = j+(num[cn+1] == 1 && cn-j < c[k+1]);
                    add(dp[i|(1<<k)][tj],dp[i][j]);
                }
            }
        }
        int ans = 0;
        for(int i = m;i <= n;i++){
            add(ans,dp[(1<<n)-1][i]);
        }
        cout << ans;
        return 0;
    }
    if(m == n){
        int ch = 1;
        for(int i = 1;i <= n;i++){
            if(num[i] == 0 || c[i] == 0){
                ch = 0;
            }
            ch = ch*i%mod;
        }
        cout << ch;
        return 0;
    }
    if(m == 1){

    }
}
