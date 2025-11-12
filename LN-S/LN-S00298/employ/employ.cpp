#include<bits/stdc++.h>
using namespace std;
namespace Aurora{ void Main(); }
int main(){ return Aurora::Main(), 0; }
namespace Aurora{
    #define ll long long
    const int N = 505, mod = 998244353;
    int n, m, s[N], c[N];
    void Solve(){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
        int ans = 1;
        for(int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
        printf("%d\n", ans);
    }
    void Main(){
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
        Solve();
    }
}