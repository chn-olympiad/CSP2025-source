#include <iostream>
using namespace std;

const int N = 505, p = 998244353;
int n, m, ans;
int c[N], fac[N];
bool s[N], vis[N];

bool chkpts(){
    for (int i = 1; i <= n; i++){
        if (!s[i]){
            return 0;
        }
    }
    return 1;
}

void solve1(){
    cout << fac[n];
}

void dfs(int x, int cnt1, int cnt2){
    if (cnt2 >= m){
        ans = (ans + fac[n - x + 1]) % p;
        return;
    }
    if (x > n){
        return;
    }
    for (int i = 1; i <= n; i++){
        if (vis[i]){
            continue;
        }
        vis[i] = 1;
        if (cnt1 >= c[i] || !s[x]){
            dfs(x + 1, cnt1 + 1, cnt2);
        }
        else{
            dfs(x + 1, cnt1, cnt2 + 1);
        }
        vis[i] = 0;
    }
}

void solve2(){
    dfs(1, 0, 0);
    cout << ans;
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = 1ll * fac[i - 1] * i % p;
    }
    for (int i = 1; i <= n; i++){
        char tmp; cin >> tmp;
        s[i] = (tmp == '1');
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    if (chkpts()){
        solve1();
    }
    else{
        solve2();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}