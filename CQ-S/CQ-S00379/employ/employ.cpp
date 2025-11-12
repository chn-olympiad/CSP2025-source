#include<bits/stdc++.h>
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define rep2(i, a, b) for(int i = a; i >= b; --i)
#define ft first
#define sd second
#define pii pair <int, int>
#define ll long long
#define pb push_back
#define gmin(a, b) a = min(a, b)
#define gmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define debug cout << "------------------\n"
const int N = 510;
using namespace std;
char s[N]; int vis[N], n, m, ans, a[N], b[N];
void dfs(int x) {
    if(x > n) {
        int cnt = 0;
        rep1(i, 1, n) if(s[i] == '1' && b[i] + cnt >= i) ++cnt;
        ans += cnt >= m; return ;
    }
    rep1(i, 1, n) if(!vis[i]) {
        vis[i] = 1; b[x] = a[i];
        dfs(x + 1); vis[i] = 0;
    }
}
void solve() {
    cin >> n >> m;
    rep1(i, 1, n) cin >> s[i];
    rep1(i, 1, n) cin >> a[i];
    dfs(1); cout << ans << '\n';
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int T = 1; //cin >> T;
    while(T--) solve();
    return 0;
}