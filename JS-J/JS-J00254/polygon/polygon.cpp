#include<bits/stdc++.h>
using namespace std;
#define ll long long

int rd(){
    int num = 0, f = 1;
    char ch;
    ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    return num * f;
}
constexpr ll N = 5000, mod = 998244353;
ll n, a[N + 5], ans;
bool f = true;
void dfs(ll s, ll t, ll cnt, ll maxn){
    if(s > n && t >= 3 && cnt > maxn + maxn){
        ans = (ans + 1) % mod;
    }
    if(s > n){
        return;
    }
    dfs(s + 1, t, cnt, maxn);
    if(a[s] > maxn){
        dfs(s + 1, t + 1, cnt + a[s], a[s]);
    }
    else{
        dfs(s + 1, t + 1, cnt + a[s], maxn);
    }
    return;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = rd();
    for(ll i = 1; i <= n; i++){
        a[i] = rd();
        if(a[i] != 1){
            f = false;
        }
    }
    if(n == 3){
        cout << ((a[1] + a[2] > a[3] && a[2] + a[3] > a[1] && a[3] + a[1] > a[2])? 1: 0);
        return 0;
    }
    if(f){
        ll num = 2, h = 2, g = 2;
        for(ll i = 3; i <= n; i++){
            num = num * i % mod;
            if(i <= n - 3){
                g = g * i % mod;
            }
        }
        for(ll i = 3; i <= n; i++){
            h = h * i % mod;
            ans = (ans + num / h / g) % mod;
            g /= max(1, int(n - i));
        }
        cout << ans;
        return 0;
    }
    dfs(1, 0, 0, 0);
    cout << ans;
    return 0;
}