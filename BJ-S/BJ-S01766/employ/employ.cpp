#include <iostream>
#include <string>
using namespace std;
const int p = 998244353,MAXN = 505;
int n,m,cnt[MAXN],sum[MAXN],fac[MAXN],inv[MAXN],f[2][MAXN][MAXN];
string s;
inline int qpow(int x,int y){
    if(!y){
        return 1;
    }
    int ret = qpow(x,y >> 1);
    ret = 1LL * ret * ret % p;
    if(y & 1){
        ret = 1LL * ret * x % p;
    }
    return ret;
}
inline int C(int x,int y){
    if(x < 0 || y < 0 || x < y){
        return 0;
    }
    return 1LL * fac[x] * inv[y] % p * inv[x - y] % p;
}
inline void trans(int i,int j,int k,int x){
    for(int c = 0;c <= cnt[j + 1];c++){
        int tmp = k - cnt[j + 1] + c;
        if(tmp >= 0){
            f[i & 1][j + 1][tmp] = (f[i & 1][j + 1][tmp] + 1LL * C(cnt[j + 1],c) * C(sum[j + 1] - k,c) % p * fac[c] % p * x) % p;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    s = '\0' + s;
    for(int i = 1;i <= n;i++){
        int c;
        cin >> c;
        cnt[c]++;
    }
    for(int i = n;~i;i--){
        sum[i] = sum[i + 1] + cnt[i];
    }
    fac[0] = 1;
    for(int i = 1;i <= n;i++){
        fac[i] = 1LL * fac[i - 1] * i % p;
    }
    inv[n] = qpow(fac[n],p - 2);
    for(int i = n - 1;~i;i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % p;
    }
    f[0][0][sum[1]] = 1;
    for(int i = 0,o = 0;i < n;i++,o ^= 1){
        for(int j = 0;j <= i + 1;j++){
            for(int k = 0;k <= sum[j + 1];k++){
                f[!o][j][k] = 0;
            }
        }
        for(int j = 0;j <= i;j++){
            for(int k = 0;k <= sum[j + 1] && k <= n - i;k++){
                trans(i + 1,j,k,1LL * (n - i - k) * f[o][j][k] % p);
                if(k){
                    if(s[i + 1] == '0'){
                        trans(i + 1,j,k - 1,f[o][j][k]);
                    }
                    else{
                        f[!o][j][k - 1] = (f[!o][j][k - 1] + f[o][j][k]) % p;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= n - m;i++){
        ans = (ans + 1LL * fac[sum[i + 1]] * f[n & 1][i][0]) % p;
    }
    cout << ans;
    return 0;
}
