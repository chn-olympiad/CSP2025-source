#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define ls (i << 1)
#define rs (i << 1 | 1)
#define mid (l + r >> 1)
using namespace std;

const int N = 505;
const int mod = 998244353;
int n, m, cnt, c[N];
ll ans, fac[N];
string s;
bitset<N> vis;
inline void dfs(int x, int ct, int l){
    if (n - x  + 1 + ct < m) return;
    if (ct >= m){
        ans += fac[n - x + 1], ans %= mod;
        return;
    }
    if (x > n){
        return;
    }
    for (int i = n; i >= 1; i--){
        if (vis[i]) continue;
        vis[i] = 1;
        if (s[x - 1] == '1' && l < c[i]){
            dfs(x + 1, ct + 1, l);
        }
        else{
            dfs(x + 1, ct, l + 1);
        }
        vis[i] = 0;
    }
}
int main(){
   //freopen("data.in", "r", stdin);
   //freopen("T3.out", "w", stdout);
   freopen("employ.in", "r", stdin);
   freopen("employ.out", "w", stdout);
   scanf("%d%d", &n, &m);
   fac[0] = 1;
   for (int i = 1; i <= n; i++){
        fac[i] = fac[i - 1] * i % mod;
   }
   cin >> s;
   for (int i = 0; i < n; i++){
        cnt += bool(s[i] == '1');
   }
   if (cnt < m){
       cout << 0;
       return 0;
   }
   for (int i = 1; i <= n; i++){
       scanf("%d", &c[i]);
   }
   sort(c + 1, c + n + 1);
   dfs(1, 0, 0);
   cout << ans;
   return 0;
}
