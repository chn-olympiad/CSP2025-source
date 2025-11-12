#include <bits/stdc++.h>
using  namespace std;
const int N = 100, mod = 998244353;
int n, a[N], ans;
bool b[N];
void dfs(int x){
    if(x == n + 1){
        int sum = 0, ma=  0;
        for(int i = 1; i <= n; i++)
            if(b[i])
                sum += a[i], ma = max(ma, a[i]);
        if(sum > ma * 2)
            ++ans, ans %= mod;
        return;
    }
    b[x] = 0;
    dfs(x + 1);
    b[x] = 1;
    dfs(x + 1);
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
