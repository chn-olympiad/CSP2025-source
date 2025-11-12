#include<bits/stdc++.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i ++)
#define per(i, s, t) for(int i = (s); i >= (t); i --)
using namespace std;
template<typename T>
inline void chmin(T& x, T y) { x = min(x, y); }
template<typename T>
inline void chmax(T& x, T y) { x = max(x, y); }
typedef long long ll;

const int p1 = 998244853, p2 = 1004535809;
const int bs1 = 31, bs2 = 97;

pair<ll, ll> gethsh(string s)
{
    ll x = 0, y = 0;
    for(char c : s)
    {
        x = (x * bs1 + c - 'a' + 1) % p1;
        y = (y * bs2 + c - 'a' + 1) % p2;
    }
    return {x, y};
}

const int N = 2e5 + 5, M = N << 2;

map<pair<pair<ll, ll>, pair<ll, ll>>, vector<pair<int, int>>> mp;
set<pair<pair<ll, ll>, pair<ll, ll>>> vis;
int sl[N], sr[N];
int tl[N], tr[N];

int n, m;
string s1[N], s2[N], t1[N], t2[N];

// struct BIT {
//     int a[M], n;
//     void upd(int q, int v) { for(int i = q; i <= n; i += (i & -i)) a[i] += v; }
//     int qry(int q) { int ans = 0; for(int i = q; i; i -= (i & -i)) ans += a[i]; return ans; }
//     void clear(int _n)
//     {
//         n = _n + 1;
//         rep(i, 0, n + 1) a[i] = 0;
//     }
// } t;

// int b[M], h;

// vector<int> add[M];
// vector<pair<int, int>> qry[M];

int ans[N];

const int C = 1e7 + 5, K = 26;
int to[C][K], idx, a[C];

int insert(int u, string s)
{
    for(char c : s)
    {
        if(!to[u][c - 'a']) to[u][c - 'a'] = ++idx;
        u = to[u][c - 'a'];
    }
    return u;
}

// vector<int> ad[C];
int fst[C], nxt[C], vt[C], h = 2;
inline void add(int x, int y)
{
    nxt[h] = fst[x], fst[x] = h, vt[h] = y, h ++;
}

void clear()
{
    rep(i, 1, idx) fst[i] = 0;
    h = 2;
    rep(i, 1, idx) memset(to[i], 0, sizeof to[i]), a[i] = 0;//, ad[i].clear();
    idx = 2;
}

int P = 0;
void dfs(int x)
{
    // for(int i : ad[x]) if(i > 0)
    for(int ii = fst[x]; ii; ii = nxt[ii])
    {
        int i = vt[ii];
        if(i < 0) continue;
        int u = insert(2, s1[i].substr(s1[i].size() - sr[i], sr[i]));
        a[u] ++;
        // if(P) cerr << "A " << s1[i].substr(s1[i].size() - sr[i], sr[i]) << " " << u << endl;
    }
    // for(int i : ad[x]) if(i < 0)
    for(int ii = fst[x]; ii; ii = nxt[ii])
    {
        int i = vt[ii];
        if(i > 0) continue;
        i = -i;
        auto tt = t1[i].substr(t1[i].size() - tr[i], tr[i]);
        // if(i == 101) cerr << P << " " << tt << endl;
        int u = 2, s = a[2];
        for(auto c : tt)
        {
            // cerr << u << " " << to[u][c - 'a'] << endl;
            if(to[u][c - 'a']) u = to[u][c - 'a'];
            else break;
            s += a[u];
            // if(i == 101) cerr << u << " " << a[u] << endl;
        }
        // if(i == 101) cerr << "Q " << i << " " << s << " " << tt << endl;
        ans[i] = s;
    }
    rep(i, 0, 25) if(to[x][i]) dfs(to[x][i]);
    // for(int i : ad[x]) if(i > 0)
    for(int ii = fst[x]; ii; ii = nxt[ii])
    {
        int i = vt[ii];
        if(i < 0) continue;
        int u = insert(2, s1[i].substr(s1[i].size() - sr[i], sr[i]));
        a[u] --;
        // if(P) cerr << "D " << s1[i].substr(s1[i].size() - sr[i], sr[i]) << " " << u << endl;
    }
}

void calc(vector<pair<int, int>> v)
{
    // h = 0;
    // for(auto [i, c] : v)
    // {
    //     if(c == 0) b[++h] = sl[i], b[++h] = sr[i];
    //     else b[++h] = tl[i], b[++h] = tr[i];

    //     if(c == 1 && i == 101)
    //     {
    //         for(auto [i, c] : v)
    //             if(c == 0)
    //                 cerr << s1[i].substr(sl[i], s1[i].size() - sl[i] - sr[i]) << " " << sl[i] << " " << sr[i] << " " << tl[101] << " " << tr[101] << endl;
    //     }
    // }
    // sort(b + 1, b + h + 1);
    // h = unique(b + 1, b + h + 1) - b - 1;
    // auto get = [&](int v) ->int { return lower_bound(b + 1, b + h + 1, v) - b; };
    // rep(i, 1, h) add[i].clear(), qry[i].clear();
    // for(auto [i, c] : v)
    // {
    //     if(c == 0) add[get(sl[i])].push_back(get(sr[i]));
    //     else qry[get(tl[i])].push_back({get(tr[i]), i});
    // }
    // t.clear(h);
    // rep(i, 1, h)
    // {
    //     for(auto j : add[i]) t.upd(j, 1);
    //     for(auto [j, id] : qry[i]) ans[id] += t.qry(j);
    // }
    
    P = 0;
    clear();
    // cerr << "==\n";
    for(auto [i, c] : v) if(c == 0)
    {
        // cerr << s1[i].substr(0, sl[i]) << endl;
        auto ss = s1[i].substr(0, sl[i]);
        reverse(ss.begin(), ss.end());
        int u = insert(1, ss);
        // ad[u].push_back(i);
        add(u, i);
    }
    for(auto [i, c] : v) if(c == 1)
    {
        P |= i == 101;
        // cerr << "T " << t1[i].substr(0, sl[i]) << endl;
        auto tt = t1[i].substr(0, tl[i]);
        reverse(tt.begin(), tt.end());
        int u = insert(1, tt);
        // ad[u].push_back(-i);
        add(u, -i);
    }
    dfs(1);
}

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> s1[i] >> s2[i];
        if(s1[i] == s2[i]) continue;

        int l = 0;
        while(s1[i][l] == s2[i][l]) l ++;
        int r = s1[i].size() - 1, rk = 0;
        while(s1[i][r] == s2[i][r]) r --, rk ++;
        auto h1 = gethsh(s1[i].substr(l, r - l + 1));
        auto h2 = gethsh(s2[i].substr(l, r - l + 1));
        mp[{h1, h2}].push_back({i, 0});
        sl[i] = l, sr[i] = rk;
        // cerr << l << " " << rk << " " << h1.first << " " << h2.first  << endl;
    }
    rep(i, 1, m)
    {
        cin >> t1[i] >> t2[i];
        if(t1[i].size() != t2[i].size()) continue;
        int l = 0;
        while(t1[i][l] == t2[i][l]) l ++;
        int r = t1[i].size() - 1, rk = 0;
        while(t1[i][r] == t2[i][r]) r --, rk ++;
        auto h1 = gethsh(t1[i].substr(l, r - l + 1));
        auto h2 = gethsh(t2[i].substr(l, r - l + 1));
        mp[{h1, h2}].push_back({i, 1});
        tl[i] = l, tr[i] = rk;
        // cerr << l << " " << rk << " " << h1.first << " " << h2.first << endl;
    }
    // rep(i, 1, m)
    // rep(i, 101, 101)
    // {
    //     int ans = 0;
    //     rep(j, 1, n)
    //     {
    //         rep(k, 0, (int)t1[i].size() - (int)s1[j].size())
    //         if(t1[i].substr(k, s1[j].size()) == s1[j])
    //         {
    //             auto tt = t1[i].substr(0, k) + s2[j] + t1[i].substr(k + s2[j].size());
    //             if(tt == t2[i])
    //             {
    //                 cerr << i << " " << j << " " << k << " " << s1[j] << " " << s2[j] << endl;
    //                 ans ++;
    //                 break;
    //             }
    //         }
    //     }
    //     cout << ans << "\n";
    // }
    for(auto [H, v] : mp)
    {
        calc(v);
    }
    rep(i, 1, m) cout << ans[i] << "\n";

    return 0;
}