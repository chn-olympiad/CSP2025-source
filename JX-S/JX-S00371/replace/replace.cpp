#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using pi = pair<int, int>;
const int N = 2500005, XN = 200005, Z = 30;
const ll base = 13163, mod = 998244853;
mt19937_64 rnd((unsigned) time(NULL));
ll rd(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rnd);
}
char s[2 * N], t[2 * N];
int n, q;
ll pw[2 * N], cw[30], hs[2 * N], inv[2 * N];
ll qpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
int dx[N], dcnt = 0;
struct ACAM{
    int ch[N][26], idx, cnt[N], net[N], sz[N];
    int h[N], hidx, ne[XN];
    vector<int> g[N];
    ll e[XN];
    void add(int u, ll hs)
    {
        e[++hidx] = hs;
        ne[hidx] = h[u];
        h[u] = hidx;
    }
    void insert(char *s, ll hs)
    {
        int p = 0;
        for(int i = 1; s[i]; i++)
        {
            int c = s[i] - 'a';
            if(ch[p][c] == 0) ch[p][c] = ++idx;
            p = ch[p][c];
        }
        cerr << "p = " << p << endl;
        add(p, hs);
        sz[p]++;
    }
    void build()
    {
        queue<int> q;
        for(int i = 0; i < 26; i++)
        {
            if(ch[0][i]) q.push(ch[0][i]);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < 26; i++)
            {
                int v = ch[u][i];
                if(v == 0)
                {
                    ch[u][i] = ch[net[u]][i];
                }
                else
                {
                    net[v] = ch[net[u]][i];
                    q.push(v);
                }
            }
        }
        for(int i = 1; i <= idx; i++)
        {
            cerr << "net_" << i << " = " << net[i] << endl;
            g[net[i]].push_back(i);
        }
    }
    void dfs(int u)
    {
        for(auto v : g[u])
        {
            dfs(v);
            sz[u] += sz[v];
        }
        cerr << "sz_" << u << " = " << sz[u] << endl;
    }
    void getdfs(int u)
    {
        for(int i = h[u]; i ; i = ne[i])
        {
            dx[++dcnt] = e[i];
        }
        for(auto v : g[u])
        {
            cerr << u << "->" << v<< endl;
            getdfs(v);
        }       
    }
}acam;

void init()
{
    pw[0] = 1; inv[0] = 1;
    for(int i = 1; i < 2 * N; i++)
    {
        pw[i] = (pw[i - 1] * base) % mod;
        inv[i] = qpow(pw[i], mod - 2);
    }
    for(int i = 0; i < Z; i++) cw[i] = rd(1, 1000000);
}

ll gethsval()
{
    ll res = 0;
    for(int i = 1; t[i]; i++)
    {
        res = (res * base + cw[t[i] - 'a']) % mod;
    }
    return res;
}

unordered_map<int, int> qcnt;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    init();
    for(int i = 1; i <= n; i++)
    {
        cin >> s + 1 >> t + 1;
        acam.insert(s, gethsval());
        cerr << i << ": " << gethsval() << endl;
    }
    acam.build();
    acam.dfs(0);
    while(q--)
    {
        cin >> s + 1 >> t + 1;
        int slen = strlen(s + 1), tlen = strlen(t + 1);
        if(slen != tlen)
        {
            cout << "0\n";
            continue;
        }
        hs[0] = 0;
        int mnp = 0x3f3f3f3f, mxp = -0x3f3f3f3f;
        for(int i = 1; i <= tlen; i++)
        {
            hs[i] = (hs[i - 1] * base + cw[t[i] - 'a']) % mod;
            if(s[i] != t[i]) mnp = min(mnp, i), mxp = max(mxp, i);

        }
        qcnt.clear();
        for(int i = 0; i < mnp; i++)
        {
            qcnt[hs[i] * base % mod * inv[i]]++;
        }
        cerr << mnp << "~" << mxp << endl;
        int p = 0, res = 0;
        for(int i = 1; i <= tlen; i++)
        {
            p = acam.ch[p][s[i] - 'a'];
            if(i < mxp) continue;
            cerr << i << ": P = " << p << endl;
            if(acam.sz[p] == 0) continue;
            dcnt = 0;
            acam.getdfs(p);
            cerr << i << ": P = " << acam.sz[p] << endl;
            for(int j = 1; j <= dcnt; j++)
            {
                ll y = dx[j];
                ll val = (hs[i] - y) % mod * inv[i] % mod;
                cerr << "y = " << y << ", hs = " << hs[i] << ", inv = " << inv[i] << endl;
                if(val < 0) val += mod;
                res += qcnt[val];
                cerr << i << ", " << j << ", val = " << val << endl;
            }
        }
        cout << res << "\n";
    }
    return 0;
}