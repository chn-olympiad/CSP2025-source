#define MAXN 1002
#include <iostream>

using namespace std;

int n;
long long k;
long long a[MAXN], f[MAXN][MAXN], dp[MAXN][MAXN];
void init(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    return;
}

void solve(){
    for(int i = 1; i <= n; ++ i){
        f[i][i] = a[i];
        dp[i][i] = 0;
        if(a[i] == k)
            dp[i][i] = 1;
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = i; j <= n; ++ j){
            f[i][j] = f[i][j - 1] ^ a[j];
        }
    }
    for(int i = n; i >= 1; -- i){
        for(int j = i + 1; j <= n; ++ j){
            dp[i][j] = 0;
            if(f[i][j] == k)
                dp[i][j] = 1;
            for(int t = i; t < j; ++ t)
                dp[i][j] = max(dp[i][j], dp[i][t] + dp[t + 1][j]);
        }
    }
    cout << dp[1][n] << endl;
    return;
}

void close(){
    fclose(stdin);
    fclose(stdout);
    return;
}

int main(){
    init();
    solve();
    close();
    return 0;
}

