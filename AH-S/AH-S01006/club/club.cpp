#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Read() {
    int sig = 1; ll x = 0; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    return x * sig;
}
void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 100005;
int n, cnt[3], c[N]; ll tmp[N];
struct tNode { ll p[3]; }a[N];
void Solve() {
    int i, j, k = 0; ll ans = 0; n = Read(), cnt[0] = cnt[1] = cnt[2] = 0;
    for(i = 1; i <= n; i++) {
        ll maxn = 0;
        for(j = 0; j < 3; j++) a[i].p[j] = Read(), maxn = max(maxn, a[i].p[j]);
        ans += maxn;
        for(j = 0; j < 3; j++) if(a[i].p[j] == maxn) { cnt[j]++, c[i] = j; break; }
    }
    int t = max(max(cnt[0], cnt[1]), cnt[2]), id = 0;
    if(t <= n / 2) { Write(ans), putchar('\n'); return ; }
    for(i = 0; i < 3; i++) if(t == cnt[i]) id = i;
    for(i = 1; i <= n; i++) if(c[i] == id) {
        ll smaxn = 0;
        tmp[++k] = a[i].p[id];
        for(j = 0; j < 3; j++) if(j != id) smaxn = max(smaxn, a[i].p[j]);
        tmp[k] -= smaxn;
    }
    sort(tmp + 1, tmp + k + 1);
    for(i = 1; i <= cnt[id] - n / 2; i++) ans -= tmp[i];
    Write(ans), putchar('\n');
}
int main() {
    freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
    int T = Read();
    while(T--) Solve();
}
