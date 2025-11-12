#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m, p[N], bk[N], c[N], Ans; string str;
inline void dfs(int dep, int res) {
    if(dep == n + 1) {
        if(n - res >= m) ++ Ans;
        return ;
    }
    for(int i = 1; i <= n; ++ i) {
        if(bk[i]) continue;
        bk[i] = 1; int u = ((c[i] <= res) || (str[dep - 1] == '0'));
        dfs(dep + 1, res + u);
        bk[i] = 0;
    }
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);  cin >> n >> m;
    cin >> str;
    for(int i = 1; i <= n; ++ i) cin >> c[i];
    dfs(1, 0); cout << Ans;
    return 0;
}
// Ren5Jie4Di4Ling5%