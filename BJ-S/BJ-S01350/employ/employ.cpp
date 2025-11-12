#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using std::cin;
using std::cout;
using std::string;
using std::map;
using std::vector;
using std::pair;
//#define DEBUG
#define freopen(...)
#ifdef DEBUG
#define debug printf
#else
#define debug(...) 0
#endif // DEBUG
const int MOD = 998244353;
struct dfs {
    int n;
    bool *s;
    int *c;
    int notAbd = 0, abd = 0;
    int finished = 0;
    dfs(int n, bool s[], int c[]) : n(n), s(s), c(c) {}
    int operator()() {
        while(s[finished]) finished++, abd++;

    }
};
struct _dfs {
    const int n, m;
    bool *s;
    int *c;
    bool *vis;
    int ans=0;
    int pos=0;
    _dfs(int n, int m, bool s[], int c[], bool vis[]) : n(n), m(m), s(s), c(c), vis(vis) {}
    void operator()(int abd=0, int notAbd=0) {
        while(pos<n && s[pos]) pos++, abd++;
        if(abd + m <= pos) {
            ans++;
            ans %= MOD;
        }
        pos++;
            if(pos >= n) {
                pos--;
                return;
            }
            while(notAbd<n && c[notAbd] <= abd) notAbd++;
            abd++;
                for(int i=0; i<notAbd; i++) {
                    if(vis[i]) continue;
                    vis[i] = 1;
                    (*this)(abd, notAbd);
                    vis[i] = 0;
                }
            abd--;
            for(int i=notAbd; i<n; i++) {
                if(vis[i]) continue;
                vis[i] = 1;
                (*this)(abd, notAbd);
                vis[i] = 0;
            }
        pos--;
    }
};
int dfs(int n, int m, bool s[], int c[]) {
    int ans = 0;
    bool vis[n];
    for(int i=0; i<n; i++) vis[i] = 0;
    auto a = _dfs(n,m,s,c,vis); a();
    return a.ans;
}
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    bool s[n]; // s[i] ? hard : easy
    int c[n];
    bool _is_A = 1;
    for(int i=0; i<n; i++) {
        char c;
        cin >> c;
        debug("%c ", c);
        s[i] = c=='0';
        if(s[i]) _is_A = 0;
    } debug("\n");
    for(int i=0; i<n; i++) cin >> c[i];
    std::sort(c, c+n);
    for(int i=0; i<n; i++) debug("%d ",c[i]); debug("\n");
    if(n <= 10) {
        long long cnt = 0;
        int p[n];
        for(int i=0; i<n; i++) p[i] = i;
        do {
            int abd = 0;
            for(int i=0; i<n; debug("  "),i++) {
                debug("%d,%d", p[i], c[p[i]]);
                if(abd >= c[p[i]]) {
                    abd++;
                    debug("X");
                    continue;
                }
                if(s[i]) {
                    abd++;
                    debug("F");
                } else {
                    debug("A");
                }
            }
            if(abd+m <= n) {
                cnt++;
                debug("ok%d", cnt);
            }
            debug("\n");
        } while(std::next_permutation(p, p+n));
        cout << cnt%MOD << "\n";
    } else if(_is_A) {
        long long ans = 1;
        for(int i=2; i<=n; i++) {
            ans *= i;
            ans %= MOD;
        }
        cout << ans << "\n";
    } else if(m==n) {
        cout << "0\n";
    } else {
        cout << dfs(n,m,s,c) << "\n";
    }
    return 0;
}
