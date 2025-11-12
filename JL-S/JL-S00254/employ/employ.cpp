#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505, mod = 998244353;

ll n, m, ans, c[N], now[N], need;
bool vis[N];
char s[N];

bool check1(){
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum+=(s[i]-'0');
    if (sum==need) return true;
    return false;
}

bool check(){
    ll sum = 0, num = 0;
    for (int i = 1; i <= n; i++){
        if (c[now[i]]<=sum||s[i]=='0') sum++;
        else{
            num++;
        }
    }
    if (num>=m) return true;
    return false;
}

void dfs(ll x){
    if (x>n){
        ans += check();
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            now[x] = i;
            vis[i] = true;
            dfs(x+1);
            vis[i] = false;
        }
    }
    return;
}

void dfs1(ll x){
    if (x>n){
        if (check1()&&check()) ans++;
        return;
    }
    s[x] = '0';
    dfs1(x+1);
    s[x] = '1';
    dfs1(x+1);
    return;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    bool f1 = true;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        if (s[i]=='0') f1 = false;
        else need++;
    }
    for (int i = 1; i <= n; i++) scanf("%lld",&c[i]);
    if (f1){
        ans = 1;
        for (int i = n; i >= 1; i--){
            ans*=i;
            ans%=mod;
        }
    }
    else if (n<=10){
        dfs(1);
    }
    else{
        for (int i = 1; i <= n; i++) now[i] = i;
        dfs1(1);
    }
    cout << ans;
    return 0;
}
