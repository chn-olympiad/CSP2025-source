#include <iostream>
#include <string>

using i64 = long long;

const int N = 505, P = 998244353;

int n, m;
int s[N], c[N];
int f[N], vis[N];
i64 cnt = 0;
i64 stag[N];

void Checks(){
    int num = 0;
    int quit = 0;
    for(int i = 1; i <= n; ++i){
        if(quit >= c[f[i]]){
            ++quit;
            continue;
        }
        if(s[i] == 0){
            ++quit;
            continue;
        }
        ++num;
    }
    if(num >= m){
        ++cnt;
    }
    return;
}

void Dfs(int x, int val){
    if(val == m){
        cnt += stag[n - x];
        cnt %= P;
        return;
    }
    if(x == n){
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(vis[i]){
            continue;
        }
        f[x + 1] = i;
        vis[i] = 1;
        int nxt;
        if(x - val >= c[i] || s[x + 1] == 0){
            nxt = val;
        }else{
            nxt = val + 1;
        }
        Dfs(x + 1, nxt);
        vis[i] = 0;
    }
    return;
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    std::string tmp;
    std::cin >> tmp;
    stag[0] = 1;
    for(i64 i = 1; i <= n; ++i){
        s[i] = tmp[i - 1] - '0';
        stag[i] = stag[i - 1] * i;
        stag[i] %= P;
    }
    for(int i = 1; i <= n; ++i){
        std::cin >> c[i];
    }

    if(n <= 18){
        Dfs(0, 0);
    }else{
        cnt = 1;
        for(int i = 2; i <= n; ++i){
            cnt *= i;
            cnt %= P;
        }
    }

    std::cout << cnt % P;
    return 0;
}