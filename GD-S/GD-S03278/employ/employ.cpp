#include<bits/stdc++.h>
using namespace std;

const int maxn = 505;
const int mod = 998244353;
int n, sum[maxn], c[maxn], fac[maxn], m, f[maxn][maxn][maxn];
string s;

void init(){
    int N = 500;
    fac[0] = 1; for(int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
}

void Add(int &x, int y){
    ((x += y) >= mod) && (x -= mod);
}

int ad(int x, int y){
    return x + y >= mod ? x + y - mod : x + y;
}

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    cin >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        sum[c[i]]++;
    }
    for(int i = 1; i <= n; i++){
        sum[i] += sum[i - 1];
    }
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= i; k++){
                if(!f[i - 1][j][k]){
                    continue;
                }
                if(s[i] == '0'){
                    Add(f[i][j + 1][k], f[i - 1][j][k]);
                }else{
                    if(sum[j] >= k){
                        int x = 1ll * f[i - 1][j][k] * (sum[j] - k) % mod;
                        Add(f[i][j + 1][k + 1], x);
                        Add(f[i][j][k + 1], mod - x);
                    }
                    Add(f[i][j][k], f[i - 1][j][k]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n - m; i++){
        for(int k = 0; k <= n; k++){
            Add(ans, 1ll * f[n][i][k] * fac[n - k] % mod);
        }
    }
    cout << ans << '\n';

    return 0;
}