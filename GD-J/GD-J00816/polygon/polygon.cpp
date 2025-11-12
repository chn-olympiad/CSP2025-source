#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 5000 + 10, maxa = 5000, mod = 998244353;

int n, res = 0;
int a[maxn], pwm[maxn], f[maxn][maxa + 10];

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n), pwm[0] = 1;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]), pwm[i] = (pwm[i - 1] << 1) % mod;
    }
    sort(a + 1, a + n + 1), f[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= maxa; j++){
            f[i][j] = f[i - 1][j], j >= a[i] && (f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod);
        }
        res = (res + pwm[i - 1]) % mod;
        for (int j = 0; j <= a[i]; j++){
            res = (res + mod - f[i - 1][j]) % mod;
        }
    }
    printf("%d", res);

return 0;
}