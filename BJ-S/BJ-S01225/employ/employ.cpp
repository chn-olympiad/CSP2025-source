#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,c[505],f[2][20][1 << 18],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 0;i < n;i++) cin >> c[i];
    if(n <= 18){
        f[0][0][0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < (1 << n);j++){
                int cnt = 0;
                for(int k = 0;k < n;k++) if((j >> k) & 1) cnt++;
                if(cnt != i) continue;
                for(int k = 0;k < n;k++) f[i & 1][k][j] = 0;
                for(int k = 0;k < n;k++){
                    if(!((j >> k) & 1)) continue;
                    for(int l = 0;l < n;l++){
                        f[i & 1][l + ((l >= c[k]) || s[i - 1] == '0')][j] += f[!(i & 1)][l][j - (1 << k)];
                        f[i & 1][l + (l >= c[k])][j] %= mod;
                    }
                }
                //for(int k = 0;k < n;k++) cout << i << '*' << k << '*' << j << '*' << f[i & 1][k][j] << ' ';
            }
        }
        for(int i = 0;i <= n - m;i++) ans = (ans + f[n & 1][i][(1 << n) - 1]) % mod;
        cout << ans;
        return 0;
    }
    return 0;
}
