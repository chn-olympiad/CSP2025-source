#define dps 799
#define I dryer
#include<bits/stdc++.h>
using namespace std;
#define r0 return 0;
#define int long long
const int N = 5000500, mod = 998244353;
int hd[N],c[N];
int bin[N],vis[N];
int n,m;
int ans = 0;
inline void dfs(int now){
    if(now == n + 1){
        int cnt = 0;
        for(int i = 1; i <= n; ++ i){
            int ps = vis[i];
            if(cnt >= c[ps] || hd[i] == 0) ++ cnt;
        }
        if(n - cnt >= m) ++ ans;
    }
    for(int i = 1; i <= n; ++ i){
        if(bin[i]) continue;
        bin[i] = 1;vis[now] = i;
        dfs(now + 1);
        bin[i] = 0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);cin >> n >> m;
    string s; cin >> s;
    for(int i = 1; i <= n; ++ i){
        hd[i] = (s[i - 1] - '0');
    }
    for(int i = 1; i <= n; ++ i){
        cin >> c[i];
    }
    dfs(1);
    cout << ans % mod << endl;
}
