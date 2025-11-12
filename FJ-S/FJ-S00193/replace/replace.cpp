#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 2e5 + 5, M = 1e6 + 5, B = 1e6, NN = 3005;
const int base = 131;
int n, q; 
void Solve1() {

}
string s[N][2]; 
int pos[N], h[N][2], ha[M], hb[M], pw[M]; 
map <pair <int, int> , int> cnt[NN];
void Solve2() {
    set <int> p; pw[0] = 1;
    for (int i = 1; i < M; i++)
        pw[i] = pw[i - 1] * base ;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        int n = s[i][0].size(); p.insert(n); 
    }
    int ts = 0;
    for (auto i : p) pos[++ts] = i;
    for (int i = 1; i <= n; i++) {
        int n = s[i][0].size();
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < n; k++)
                h[i][j] = h[i][j] * base + s[i][j][k] - 'a' + 1;
        int id = lower_bound(pos + 1, pos + 1 + ts, n) - pos; 
        cnt[id][{h[i][0] * pw[B - n], h[i][1] * pw[B - n]}]++;
    }
    while (q--) {
        string a, b; cin >> a >> b; int n = a.size();
        int L = 0, R = n - 1;
        while (a[L] == b[L]) L++;
        while (a[R] == b[R]) R--;
        for (int i = 0; i < n; i++) {
            ha[i] = (i ? ha[i - 1] * base : 0) + a[i] - 'a' + 1;
            hb[i] = (i ? hb[i - 1] * base : 0) + b[i] - 'a' + 1;
        }
        int ans = 0; 
        for (int i = 1; i <= ts; i++) 
            for (int l = 0; l <= L; l++) {
                int r = l + pos[i] - 1, len = pos[i];
                if (r < R || r >= n) continue; 
                int x = (ha[r] - ha[l - 1] * pw[len + 1]) * pw[B - r];
                int y = (hb[r] - hb[l - 1] * pw[len + 1]) * pw[B - r];
                ans += cnt[i][{x, y}]; 
            }
        cout << ans << '\n';
    }
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout); 
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
     cin >> n >> q;
    // if (q == 1) Solve1();
    // else 
    Solve2();
    return 0; 
}