#include <bits/stdc++.h>
using namespace std;
int n, m, c[20], d[20], p, b[20], f[20];
string s ;

bool check(){
    int num = 0;
    for (int i = 1; i <= n; i++){
        d[i] = d[i - 1];
        if (s[i] == '0'){
            d[i]++;
            continue;
        }
        if (d[i] >= c[b[i]]){
            d[i]++;
            continue;
        }
        if (s[i] == '1'){
            num++;
        }
    }
    if (num >= m) return 1;
    return 0;
}

void dfs(int pos){
    if (pos == n + 1){
        if (check()) p++;
        p %= 998244353;
    }
    for (int i = 1; i <= n; i++){
        if (!f[i]){
            b[pos] = i;
            f[i] = 1;
            dfs(pos + 1);
            f[i] = 0;
        }
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    dfs(1);
    cout << p;
    return 0;
}
