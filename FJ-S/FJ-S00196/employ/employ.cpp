#include<bits/stdc++.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i ++)
#define per(i, s, t) for(int i = (s); i >= (t); i --)
using namespace std;
template<typename T>
inline void chmin(T& x, T y) { x = min(x, y); }
template<typename T>
inline void chmax(T& x, T y) { x = max(x, y); }
typedef long long ll;

const int N = 505, p = 998244353;
int n, m, a[N], s[N], c[N], cnt[N];

const int M = 18;
int f[1 << M][M];

int fac[N], ifac[N];

ll qpow(ll a, ll b)
{
    if(!b) return 1;
    return ((b & 1) ? a : 1ll) * qpow(a * a % p, b >> 1) % p;
}

void init()
{
    fac[0] = 1; rep(i, 1, N - 1) fac[i] = 1ll * fac[i - 1] * i % p;
    ifac[N - 1] = qpow(fac[N - 1], p - 2);
    per(i, N - 2, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % p;
    ifac[0] = 1;
}

ll C(ll a, ll b)
{
    if(a > b || a < 0 || b < 0) return 0;
    return 1ll * fac[a] * ifac[b] % p * ifac[a - b] % p;
}

inline void add(int& x, ll y)
{
    x = (x + y) % p;
}

void sol1()
{
    f[0][0] = 1;
    rep(i, 0, (1 << n) - 1)
    {
        int c = __builtin_popcount(i);
        // rep(t, 0, c) cerr << i << " " << t << " " << f[i][t] << endl;
        rep(t, 0, c)
        rep(j, 0, n - 1) if(!((i >> j) & 1))
        {
            // cerr << i << " " << t << " " << j << " " << (s[c + 1] == 0 || a[j + 1] >= t) << endl;
            if(s[c + 1] == 0 || a[j + 1] <= t) add(f[i | (1 << j)][t + 1], f[i][t]);
            else add(f[i | (1 << j)][t], f[i][t]);
        }
    }
    int ans = 0;
    rep(i, 0, n) if(n - i >= m) add(ans, f[(1 << n) - 1][i]);
    cout << ans;
}

int c1[N];

void sol2()
{
    per(i, n, 1) c1[i] = c1[i + 1] + s[i];
    static int f[N][N];
    sort(a + 1, a + n + 1);
    f[n + 1][0] = 1;
    per(i, n, 1)
    {
        rep(j, 0, c[n])
        {
            int t = max(0, c1[a[i] + 1] - (n - i - j));
            add(f[i][j], 1ll * f[i + 1][j] * t % p);
            add(f[i][j + 1], 1ll * f[i + 1][j] * (c[n] - j) % p);
        }
    }
    int ans = (fac[n] - f[1][c[n]] + p) % p;
    cout << ans;
}

void sol3()
{
    static int f[1 << M] = {}, g[1 << M] = {};
    vector<int> pos;
    rep(i, 1, n) if(s[i] == 1) pos.push_back(i);
    int k = pos.size();
    // cerr << k << endl;
    per(i, n, 1) cnt[i] += cnt[i + 1];
    int ans = 0;
    rep(i, 0, (1 << k) - 1)
    {
        vector<int> v;
        rep(j, 0, k - 1) if((i >> j) & 1) v.push_back(pos[j]);
        sort(v.begin(), v.end());
        int t = v.size();
        if(t < m) continue;
        rep(j, 0, t - 1)
        {
            v[j] -= j;
        }
        sort(v.begin(), v.end());

        int res = 1;
        per(j, t - 1, 0)
        {
            // cerr << "! " << v[j] << " " << cnt[v[j]] << endl;
            res = 1ll * res * max(0, cnt[v[j]] - (t - j - 1)) % p;
        }
        // cerr << res << endl;
        f[i] = 1ll * res * fac[n - t] % p;
        // cerr << i << " " << f[i] << endl;
    }
    rep(i, 0, (1 << k) - 1) if(__builtin_popcount(i) >= m)
    {
        int S = ((1 << k) - 1) ^ i;
        for(int j = S; ; j = (j - 1) & S)
        {
            int o = j | i;
            if(!__builtin_parity(i ^ o)) add(g[i], f[o]);
            else add(g[i], -f[o]);
            if(!j) break;
        }
        // cerr << i << " " << g[i] << endl;
        add(ans, g[i]);
    }
    cout << (ans + p) % p;
}

signed main()
{
    init();
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    string S; cin >> S;
    rep(i, 1, n)
    {
        s[i] = S[i - 1] == '1';
        c[i] = c[i - 1] + (s[i] == 0);
    }
    rep(i, 1, n) cin >> a[i], cnt[a[i]] ++;

    if(n <= 18) return sol1(), 0;
    if(m == 1) return sol2(), 0;
    if(c[n] >= n - 18) return sol3(), 0;
    

    return 0;
}