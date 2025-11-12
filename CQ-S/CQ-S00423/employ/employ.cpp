#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bits/extc++.h>
#define int long long
using namespace std;
namespace Read{
    inline int read(){
        int f = 0, d = 1; char op;
        while(op = getchar(), !isdigit(op)) if(op == '-') d = - 1;
        while(isdigit(op)) f = (f << 1) + (f << 3) + (op ^ 48), op = getchar();
        return f * d;
    }
} using namespace Read;
namespace YYY{
    const int N = 510, K = 20, Mod = 998244353;
    int n, m;
    int f[N][N], tong[N]; string s;
    int c[N][N], jie[N];
    
    int val[N], idx_val; bool vis[N];
    int tmp[N], ans;

    void dfs(int u){
        if(u == n + 1){
            int cnt = 0;
            int count = 0;
            for(int i = 1; i <= n; i ++ ){
                if(s[i - 1] == '1'){
                    if(count < tmp[i]){
                        cnt ++ ;
                    }
                    else{
                        count ++ ;
                    }
                }
                else{
                    count ++ ;
                }
            }
            if(cnt >= m) ans ++ ;
            return ;
        }
        for(int i = 1; i <= n; i ++ ){
            if(!vis[i]){
                vis[i] = true; tmp[u] = val[i];
                dfs(u + 1);
                vis[i] = false;
            }
        }
    }
    void sol1(){
        for(int i = 0; i <= n; i ++ ){
            for(int j = 1; j <= tong[i]; j ++ ) val[ ++ idx_val] = i;
        }
        dfs(1);
        cout<<ans<<'\n';
    }


    signed main(){
        n = read(), m = read();
        for(int i = 0; i <= n; i ++ ) c[0][i] = 1;
        jie[0] = 1;
        for(int i = 1; i <= n; i ++ ) jie[i] = jie[i - 1] * i % Mod;
        for(int i = 1; i <= n; i ++ ){
            for(int j = i; j <= n; j ++ ) c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % Mod;
        }
        cin >> s;
        int x;
        for(int i = 1; i <= n; i ++ ) x = read(), tong[x] ++ ;
        if(n <= 10){
            sol1(); return 0;
        }
        // if(tong[0] == 0){
        //     int ans = 1;
        //     for(int i = 1; i <= n; i ++ ) ans = ans * i % Mod;
        //     cout<<ans<<'\n';
        //     return 0;
        // }
        f[0][0] = jie[tong[0]]; int sum = tong[0];
        int ans = 0;
        for(int i = 1; i <= n + 1; i ++ ){
            for(int j = 0; j <= n; j ++ ){
                if(f[i - 1][j] == 0) continue;
                int cnt = sum - j - (i - 1);
                if(cnt == 0){
                    if(j + (n - sum) >= m) ans = (ans + f[i - 1][j] * jie[n - sum] % Mod * c[n - sum][n]) % Mod;
                    continue;
                }
                if(i == n + 1) continue;
                for(int k = 0; k <= tong[i]; k ++ ){
                    f[i][j + k] = (f[i][j + k] + f[i - 1][j] * c[k][j + k + i - 1] % Mod * c[tong[i] - k][cnt - 1 + (tong[i] - k)] % Mod * jie[tong[i]]) % Mod;
                }
            }
            sum += tong[i];
        }
        cout<<ans<<'\n';
        return 0;
    }
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    return YYY::main();
}
/*
g++ employ.cpp -o employ -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\employ.exe < a.in > a.out

g++ employ.cpp -o employ -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\employ.exe < D:\CQ-S00423\employ\employ1.in > a.out && fc a.out D:\CQ-S00423\employ\employ1.ans
.\employ.exe < D:\CQ-S00423\employ\employ2.in > a.out && fc a.out D:\CQ-S00423\employ\employ2.ans
.\employ.exe < D:\CQ-S00423\employ\employ3.in > a.out && fc a.out D:\CQ-S00423\employ\employ3.ans

*/