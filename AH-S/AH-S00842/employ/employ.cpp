#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const long long mod = 998244353;
int n, m, nd, c[N];
bool vis[N];
string s;
long long ans = 0;
void dfs(int id, int sm){
    if(id == n + 1){
        if(sm <= nd) ans = (ans + 1) % mod;
        return;
    }
    if(sm > nd) return;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            if(s[id] == '1' && sm < c[i]) dfs(id + 1, sm);
            else dfs(id + 1, sm + 1);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    nd = n - m;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
