#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for(int i = s, rep##i = t; i <= rep##i; ++i)
#define per(i, t, s) for(int i = t, per##i = s; i >= per##i; --i)
#define gc getchar
typedef long long ll;

int rd() {
    int x = 0, f = 0;
    char ch = gc();
    while(!isdigit(ch)) {if(ch == '-') f = 1; ch = gc();}
    while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
    return f ? -x : x;
}

int rd01() {
    char ch = gc();
    while(!isdigit(ch)) ch = gc();
    return ch - '0';
}

constexpr int N = 505, mod = 998244353;
int n, s[N], c[N], p[N], m;

void solve() {
    n = rd(), m = rd();
    rep(i, 1, n) s[i] = rd01();
    rep(i, 1, n) c[i] = rd();
    ll ans = 1;
    rep(i, 1, n) ans = ans * i % mod;
    printf("%lld\n", ans);
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    solve();
    return 0;
}