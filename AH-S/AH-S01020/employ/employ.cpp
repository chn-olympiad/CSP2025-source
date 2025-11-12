#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll n, m, c[510], a[510], ans;
bool xzA = 1, f[510];
string s;
bool check(){
    int tt = 0;
    for(int i=1; i<=n; i++){
        if(s[i - 1] == '0' || tt >= a[i]) tt++;
        if(tt > n - m) return false;
    }
    return true;
}
void dfs(int cur){
    if(cur >= n + 1){
        if(check()) ans = (ans + 1) % MOD;
        return;
    }
    for(int i=1; i<=n; i++){
        if(f[i]) continue;
        a[cur] = c[i];
        f[i] = 1;
        dfs(cur + 1);
        f[i] = 0;
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    cin >> s;
    for(int i=1; i<=n; i++) scanf("%lld", &c[i]);
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
            xzA = 0;
            break;
        }
    }
    if(xzA){
        for(int i=1; i<=n; i++){
            ans = (ans * i) % MOD;
        }
        printf("%lld", ans);
        return 0;
    }
    else if(m == n && !xzA){
        printf("0");
        return 0;
    }
    else if(n <= 10){
        dfs(1);
        printf("%lld", ans % MOD);
    }
    return 0;
}
