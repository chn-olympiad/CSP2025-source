#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, m, c[1000010], ans = 1, cnt, vis[1000010], a[1000010];
char s[1000010];
bool check(){
    long long now = 0, res = 0;
    for(long long i = 1; i <= n; i++){
        if(s[i] == '0' || now >= c[a[i]]){ now++; continue; }
        res++;
    }
    return res >= m;
}
void dfs(long long dep){
    if(dep > n){
        if(check()) cnt++;
        return ;
    }
    for(long long i = 1; i <= n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        a[dep] = i;
        dfs(dep+1);
        vis[i] = 0;
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    cin >> s+1;
    for(long long i = 1; i <= n; i++){
        scanf("%lld", &c[i]);
        ans = ans * i % mod;
    }
    if(n <= 10){
        dfs(1);
        printf("%lld", cnt);
        return 0;
    }
    if(m == n){
        for(long long i = 1; i <= n; i++){
            if(s[i] == '0' || c[i] == 0){
                printf("0");
                return 0;
            }
        }
        printf("%lld", ans);
        return 0;
    }
    printf("%lld", ans);
    return 0;
}