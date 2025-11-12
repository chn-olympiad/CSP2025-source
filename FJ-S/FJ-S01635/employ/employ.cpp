#include<bits/stdc++.h>

using namespace std;

const int N = 509, P = 998244353;

int n, m;
char a[N];
int c[N];
int d[N], e[N];
long long f[2][N][N], g[2][N][N];
long long C[N][N];
long long fac[N];

void init(){
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i-1] * i % P;
    for(int i = 0; i < N; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
        }
    }
}

int main(){

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    init();

    scanf("%d%d", &n, &m);
    scanf("%s", a+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
        d[c[i]]++;
    }
    e[0] = d[0];
    for(int i = 1; i <= n; i++){
        e[i] = e[i-1] + d[i];
    }

    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        int p = (i&1);
        memset(g[p], 0, sizeof(g[p]));
        memset(f[p], 0, sizeof(f[p]));
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++){
                long long nw = f[p^1][j][k];
                if(!nw) continue;
                if(a[i] == '0'){
                    (g[p][j+1][k+1] += nw * max(0, e[j]-k)) %= P;
                    (g[p][j+1][k] += nw) %= P;
                }else{
                    (g[p][j+1][k+1] += nw * max(0, e[j]-k)) %= P;
                    (f[p][j][k] += nw) %= P;
                }
            }
        }
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= i; k++){
                long long nw = g[p][j][k];
                if(!nw) continue;
                for(int l = 0; l <= d[j]; l++){
                    if(k+l <= n) (f[p][j][k+l] += nw * C[i-k][l]%P*C[d[j]][l]%P * fac[l]) %= P;
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i <= n-m; i++){
        long long tp = 1;
        int s = 0;
        for(int j = i+1; j <= n; j++){
            s += d[j];
            tp = tp * C[s][d[j]] % P;
            tp = tp * fac[d[j]] % P;
        }
        (ans += f[n&1][i][e[i]] * tp%P) %= P;
    }
    ans %= P; ans += P; ans %= P;
    printf("%lld\n", ans);

    return 0;
}