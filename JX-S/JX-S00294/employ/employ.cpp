#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;
const int N = 1e5 + 5, P = 998244353;
int n, m;
char s[N];
int p[N], c[N];
bool st[N];
inline bool check(){
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (cnt >= c[p[i]] || s[i] == '0') cnt ++ ;
    return n - cnt >= m;
}
LL res = 0;
inline void dfs(int u){
    if (u == n + 1){
        res += check();
        if (res >= P) res %= P;
        return;
    }
    for (int i = 1; i <= n; i ++ )
        if (!st[i]){
            st[i] = true;
            p[u] = i;
            dfs(u + 1);
            st[i] = false;
        }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; i ++ ) cin >> s[i];
    for (register int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
    dfs(1);
    printf("%lld\n", res);
    return 0;
}

