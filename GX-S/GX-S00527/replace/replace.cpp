#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for(int i = s, rep##i = t; i <= rep##i; ++i)
#define per(i, t, s) for(int i = t, per##i = s; i >= per##i; --i)
#define gc getchar
#define pb push_back
typedef long long ll;

constexpr int mod = 998244353, d = 29;
int n, m;
vector<string> s1, s2, t1, t2;

constexpr int N1 = 2005;
int hs1[2005], hs2[2005], dd[2005];
int ht1[2005], ht2[2005];

int seq1(int l, int r) {
    if(l > r) return 0;
    return (ht1[r] - (ll)ht1[l - 1] * dd[r - l + 1] % mod + mod) % mod;
}
int seq2(int l, int r) {
    if(l > r) return 0;
    return (ht2[r] - (ll)ht2[l - 1] * dd[r - l + 1] % mod + mod) % mod;
}
void solve1() {
    dd[0] = 1;
    rep(i, 1, 2000) dd[i] = (ll)dd[i - 1] * d % mod;
    
    rep(i, 0, n - 1) {
        rep(j, 0, s1[i].size() - 1) {
            hs1[i] = ((ll)hs1[i] * d % mod + (s1[i][j] - 'a')) % mod; 
            hs2[i] = ((ll)hs2[i] * d % mod + (s2[i][j] - 'a')) % mod; 
        }
    }

    rep(i, 0, m - 1) {
        int ans = 0;
        ht1[0] = ht2[0] = 0;
        rep(j, 0, t1[i].size() - 1) {
            ht1[j + 1] = ((ll)ht1[j] * d % mod + (t1[i][j] - 'a')) % mod;
            ht2[j + 1] = ((ll)ht2[j] * d % mod + (t2[i][j] - 'a')) % mod;
        }
        rep(j, 0, n - 1) {
            int lns = s1[j].size(), lnt = t1[i].size();
            for(int l = 1, r = lns; r <= lnt; l++, r++) {
                if(seq1(1, l - 1) == seq2(1, l - 1) && seq1(r + 1, lnt) == seq2(r + 1, lnt) 
                && seq1(l, r) == hs1[j] && seq2(l, r) == hs2[j]) ans++;
            }
        }
        cout << ans << '\n';
    }
}

constexpr int N2 = 7000005;
struct Node {
    int ln, b1, b2, id, dt;
} ps[N2], pt[N2];

bool cmp(const Node &x, const Node &y) {
    if(x.dt != y.dt) return x.dt < y.dt;
    if(x.b1 != y.b1) return x.b1 < y.b1;
    if(x.b2 != y.b2) return x.b2 < y.b2;
    return 1;
}
int arr[N2], ans2[N2];
void add(int k, int x) {if(!k) return;for(; k <= N2-5; k += k & -k) arr[k] += x;}
int get(int k) {int res = 0; for(; k; k -= k & -k) res += arr[k]; return res;}
void solve2() {
    rep(i, 0, n - 1) {
        ps[i + 1].ln = s1[i].size();
        rep(j, 0, s1[i].size() - 1) {
            if(s1[i][j] == 'b') { ps[i + 1].b1 = j + 1; break; }
        }
        rep(j, 0, s2[i].size() - 1) {
            if(s2[i][j] == 'b') { ps[i + 1].b2 = j + 1; break; }
        }
        ps[i + 1].id = i + 1;
        ps[i + 1].dt = ps[i + 1].b2 - ps[i + 1].b1;
        ps[i + 1].b1--;
        ps[i + 1].b2 = ps[i + 1].ln - ps[i + 1].b2;
    }

    rep(i, 0, m - 1) {
        pt[i + 1].ln = t1[i].size();
        rep(j, 0, t1[i].size() - 1) {
            if(t1[i][j] == 'b') { pt[i + 1].b1 = j + 1; break; }
        }
        rep(j, 0, t2[i].size() - 1) {
            if(t2[i][j] == 'b') { pt[i + 1].b2 = j + 1; break; }
        }
        pt[i + 1].id = i + 1;
        pt[i + 1].dt = pt[i + 1].b2 - pt[i + 1].b1;
        pt[i + 1].b1--;
        pt[i + 1].b2 = pt[i + 1].ln - pt[i + 1].b2;
    }

    sort(ps + 1, ps + n + 1, cmp);
    sort(pt + 1, pt + m + 1, cmp);

    // rep(i, 1, n) cout << ps[i].dt << ' ' << ps[i].b1 << ' ' << ps[i].b2 << '\n';

    // rep(i, 1, m) cout << pt[i].dt << ' ' << pt[i].b1 << ' ' << pt[i].b2 << '\n';

    int p1 = 1, p2 = 1;
    // cout << "ok\n";
    while(p2 <= m) {
        int l = p2, r = p2;
        while(r < m && pt[r + 1].dt == pt[l].dt) r++;
        
        while(p1 <= n && ps[p1].dt < pt[l].dt) p1++;
        int tp1 = p1, dtt = pt[l].dt;
        rep(i, l, r) {
            while(p1 <= n && ps[p1].dt == dtt && ps[p1].b1 <= pt[i].b1) {
                // cout << ps[p1].dt << ' ' << ps[p1].b1 << ' ' << ps[p1].b2 << '\n';
                add(ps[p1].b2 + 1, 1);
                p1++;
            }
            // cout << pt[i].id << ' ' <<  pt[i].b2 << ' ' << get(pt[i].b2) << '\n';
            ans2[pt[i].id] += get(pt[i].b2 + 1);
        }
        rep(i, tp1, p1 - 1) add(ps[i].b2 + 1, -1);
        p2 = r + 1;
    }
    rep(i, 1, m) cout << ans2[i] << '\n';
}

void solve() {
    cin >> n >> m;
    string r1, r2;
    int L1 = 0, L2 = 0;
    rep(i, 1, n) {
        cin >> r1 >> r2;
        L1 += r1.size() + r2.size();
        s1.pb(r1), s2.pb(r2);
    }
    rep(i, 1, m) {
        cin >> r1 >> r2;
        L2 += r1.size() + r2.size();
        t1.pb(r1), t2.pb(r2);
    }
    if(L1 <= 2000 && L2 <= 2000) solve1();
    else solve2();
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    solve();
    return 0;
}