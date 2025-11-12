#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5, M = 3e6 + 5, B = 500, base = 10007;
int n, q, cnt, lsh[N];
ull hs[N][2], pw[M];
bool flg[N];
namespace H {
    const int S = 1e7 + 3;
    int head[S], nxt[N], tot[N], cnt = 0;
    ull A[N], B[N];
    void insert(ull a, ull b) {
        int k = (a * 998244353 + b) % S;
        for(int p = head[k]; p; p = nxt[p]) if(A[p] == a && B[p] == b) return tot[p]++, void();
        nxt[++cnt] = head[k], head[k] = cnt, A[cnt] = a, B[cnt] = b, tot[cnt] = 1;
        // cerr<<cnt<<'\n';
    }
    int ask(ull a, ull b) {
        int k = (a * 998244353 + b) % S;
        // cerr<<head[k]<<' '<<A[1]<<' '<<B[1]<<' '<<tot[1]<<'\n';
        for(int p = head[k]; p; p = nxt[p]) if(A[p] == a && B[p] == b) return tot[p];
        return 0;
    }
}
struct node {
    ull a, b;
    int l;
} arr[N];
ull ask(int l, int r, bool op) {return hs[r][op] - hs[l - 1][op] * pw[r - l + 1];}
inline void SOLVE() {
    cin>>n>>q;
    for(int i = 1; i <= n; i++) {
        string s, t;
        cin>>s>>t; int l = s.length();
        ull a = 0, b = 0;
        for(int j = 0; j < l; j++) a = a * base + s[j], b = b * base + t[j];
        // cerr<<a<<' '<<b<<'\n';
        // if(s == "g" && t == "p") cerr<<a<<' '<<b<<'\n';
        if(l <= B) H::insert(a, b), flg[l] = true;
        else arr[++cnt] = {a, b, l};
    }
    sort(arr + 1, arr + cnt + 1, [](node a, node b) {return a.l > b.l;});
    for(int i = 1; i <= n; i++) lsh[i] = -arr[i].l;
    cerr<<cnt<<'\n';
    while(q--) {
        string s[2];
        cin>>s[0]>>s[1]; int ls = s[0].length();
        if(s[0].length() != s[1].length()) {cout<<0<<'\n'; continue;}
        s[0] = '#' + s[0], s[1] = '#' + s[1];
        for(int i = 1; i <= ls; i++) {
            hs[i][0] = hs[i - 1][0] * base + s[0][i];
            hs[i][1] = hs[i - 1][1] * base + s[1][i];
        }
        int L = 1, R = ls, ans = 0;
        for(int i = 1; i <= ls; i++) if(s[0][i] != s[1][i]) {L = i; break;}
        for(int i = ls; i >= 1; i--) if(s[0][i] != s[1][i]) {R = i; break;}
        // cerr<<ask(1, 1, 0)<<' '<<ask(1, 1, 1)<<' '<<H::ask(ask(1, 1, 0), ask(1, 1, 1))<<'\n';
        for(int len = R - L + 1; len <= ls && len <= B; len++) if(flg[len])
            for(int l = max(len, R) - len + 1, r = max(len, R); r <= ls && l <= L; l++, r++)
                ans += H::ask(ask(l, r, 0), ask(l, r, 1));
        int p = lower_bound(lsh + 1, lsh + cnt + 1, -ls) - lsh;
        for(int i = p; i <= cnt; i++) {
            if(arr[i].l < R - L + 1) break;
            for(int l = max(R, arr[i].l) - arr[i].l + 1, r = max(R, arr[i].l); r <= ls && l <= L; l++, r++)
                if(arr[i].a == ask(l, r, 0) && arr[i].b == ask(l, r, 1)) ans++;
        }
        cout<<ans<<'\n';
    }
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for(int i = pw[0] = 1; i < M; i++) pw[i] = pw[i - 1] * base;
    int t = 1;
    while(t--) SOLVE();
    cerr<<clock() * 1.0 / CLOCKS_PER_SEC<<'\n';
    return 0;
}
//g++ -o -std=c++14 -O2 -DddxrS; ./