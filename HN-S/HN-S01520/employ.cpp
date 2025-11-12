#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 505, mod = 998244353;

int n, m, c[N], p[N];
ll ans;
string s;
bool f[N];

bool ck(){
    int cnt = 0, lc = 0;
    for(int i = 1; i <= n; i++){
        if(cnt >= c[p[i]]){
            cnt++;
        }else{
            if(s[i - 1] == '0'){
                cnt++;
            }else{
                lc++;
                if(lc >= m){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void dfs(int x){
    if(x == n + 1){
        ans = (ans + ck()) % mod;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!f[i]){
            f[i] = 1;
            p[x] = i;
            dfs(x + 1);
            f[i] = 0;
        }
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}
