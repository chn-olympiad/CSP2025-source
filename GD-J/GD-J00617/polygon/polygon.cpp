#include<bits/stdc++.h>
using namespace std;

int const MOD = 998244353;
int const N = 5005;
int a[N], C[N][N];
int sum[N];
int n;
int p;

void init_C(){
    C[1][1] = C[2][1] = C[2][2] = 1;
    sum[1] = 1, sum[2] = 2;
    for(int i = 3; i < N; i++)
        for(int j = 1; j <= i; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            sum[i] = (sum[i] + C[i][j]) % MOD;
        }
}

bool check(){
    bool flag = 1;
    for(int i = 1; i <= n; i++) if(a[i] != 1) {flag = false; break;}
    return flag;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n <= 27){
        int U = 1 << n;
        for(int i = 1; i < U; i++){
            int ans = 0, Max = -1, cnt = 0;
            for(int j = 0; j < n; j++)
                if(i & (1 << j)) {Max = max(Max, a[j + 1]); ans = ans + a[j + 1]; cnt ++;}
            if(ans > Max * 2 && cnt >= 3) p++;
            p %= MOD;
        }
        cout << p << "\n";
    }else{
        if(check()){
            init_C();
            cout << (sum[n] - C[1][n] - C[2][n]) % MOD << "\n";
        }
    }   

    return 0;
}


// Kasty's code