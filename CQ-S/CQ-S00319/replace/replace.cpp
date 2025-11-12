#include<bits/stdc++.h> 
bool Mbe;
using namespace std;
#define il inline
typedef long long ll;
typedef double db;
#define fi first
#define se second 
typedef array<int,3> ai3;
const int MAXN=5e6;
template<typename t1> il bool cmax(t1&x, const t1&y) { return x<y?x=y,1:0; }
template<typename t1> il bool cmin(t1&x, const t1&y) { return y<x?x=y,1:0; }
#define sz(x) ((int)x.size())
#define m0(x) (memset(x, 0, sizeof x))
#define clr(x) (x.erase(x.begin(), x.end()))

typedef pair<int,int> pii;
const pii mul={131, 1331}, mod={1e9+9, 998244853};
il pii operator*(pii c, pii d) {return {(ll)c.fi*d.fi%mod.fi, (ll)c.se*d.se%mod.se}; }
il pii operator+(pii c, pii d) {return {(c.fi+d.fi)%mod.fi, (c.se+d.se)%mod.se}; }
// il pii operator-(pii c, pii d) {return {(c.fi+mod.fi-d.fi)%mod.fi, (c.se+mod.se-d.se)%mod.se}; }
il pii gethash(string&s, int l, int r, pii re={0,0}) {
    for (int i=l; i<=r; ++i) re=re*mul+pii{s[i],s[i]};; return re;
}

int n, q, m, ans[MAXN+3]; string s1, s2, x[MAXN+3], z[MAXN+3]; 
struct node { pii h1,h2; int id; } a[MAXN+3];
il bool operator<(const node&c, const node&d) {return c.h1!=d.h1?c.h1<d.h1:(c.h2!=d.h2?c.h2<d.h2:c.id<d.id); }
vector<int> adj[MAXN+3], vec[MAXN+3];
namespace tr {
    int cnt, ch[MAXN+3][26], tot[MAXN+3];
    il int newnode() {return ++cnt, m0(ch[cnt]), tot[cnt]=0, cnt; }
    il void cler() { cnt=0;}
    il void ins1(const string&s, int insx) {
        int now=cnt?1:newnode(); 
        for (char c:s) 
            !ch[now][c-'a']?ch[now][c-'a']=newnode(), adj[now].push_back(ch[now][c-'a']),1:0, 
            now=ch[now][c-'a'];
        vec[now].push_back(insx); 
    }
    il void ins2(const string&s, int addx) {
        int now=cnt?1:newnode(); 
        for (char c:s) 
            !ch[now][c-'a']?ch[now][c-'a']=newnode(),1:0, 
            now=ch[now][c-'a'];
        tot[now]+=addx; 
    }
    il int get(const string&s) {
        int now=cnt?1:newnode();
        int re=tot[now]; 
        for (char c:s) 
            !ch[now][c-'a']?ch[now][c-'a']=newnode(),1:0, 
            now=ch[now][c-'a'], re+=tot[now];
        return re;
    }
}
namespace T {
    int n; 
    il void dfs1(int u) {
        // cerr << "dfs1: " << u << endl;
        for (int p:vec[u]) 
            if (
                // cerr << ' ' << p << endl, 
                p<=::n) tr::ins2(z[p], +1); 
            else ans[p-::n]+=tr::get(z[p]);//, cerr << " a: " << p << ' ' << p-::n << ' ' << tr::get(z[p]) << endl;
        // tim=tr::cnt;
        for (int v:adj[u]) dfs1(v);
        for (int p:vec[u]) if (p<=::n) tr::ins2(z[p], -1); else break;
    }
    il void clear() {
        for (int i=0; i<=n; ++i) adj[i].clear(), vec[i].clear();
    }
}

il void solve() {
    cin >> n >> q;
    for (int ni=1, l, r; ni<=n+q; ++ni) {
        cin >> s1 >> s2;
        if (sz(s1)!=sz(s2)) continue; 
        for (l=0; l<sz(s1)&&s1[l]==s2[l]; ++l); 
        if (l==sz(s1)) continue; 
        for (r=sz(s1)-1; r>=0&&s1[r]==s2[r]; --r);
        ++m, a[m].id=ni, a[m].h1=gethash(s1,l,r), a[m].h2=gethash(s2,l,r);
        for (int i=l-1; i>=0    ; --i) x[ni]+=s1[i]; // s2[i]
        for (int i=r+1; i<sz(s1); ++i) z[ni]+=s1[i]; // s2[i]
        // cerr << ni << ' ' << x[ni] << ' ' << z[ni] << ' ' << l << ' ' << r << ' ' << a[m].h1.fi << ' ' << a[m].h1.se << ' ' << a[m].h2.fi << ' ' << a[m].h2.se << endl;
    }
    sort(a+1, a+1+m);
    for (int nl=1, nr=1; nl<=m; nl=nr) {
        for (; nr<=m&&a[nl].h1==a[nr].h1&&a[nl].h2==a[nr].h2; ++nr);
        // cerr << nl << ' ' << nr << endl;
        for (int i=nl; i<nr; ++i) tr::ins1(x[a[i].id], a[i].id)
        // ,cerr << ' ' << a[i].id << ' ' << x[a[i].id] << ' ' << z[a[i].id] << ' ' << a[i].h1.fi << ' ' << a[i].h1.se << ' ' << a[i].h2.fi << ' ' << a[i].h2.se << endl
        ;
        T::n=tr::cnt, tr::cler(), T::dfs1(1), tr::cler(), T::clear();//, tr::back(1);
    }
    for (int qi=1; qi<=q; ++qi) cout << ans[qi] << '\n';
}
db Tbe; bool Men;
int main() {
#ifdef MYFRE
    Tbe=clock();
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
    solve();
    // int t; cin >> t; while (t--) solve();
#ifdef MYFRE
    cerr << "M: " << (&Mbe-&Men)/1024.0/1024 << " T: " <<  (clock()-Tbe)/1e6 << endl;
#endif
}

// namespace tr {
//     int cnt, ch[MAXN+3][26], tot[MAXN+3]; pii f[MAXN+3];
//     il int newnode(int fa, int c) {return ++cnt, m0(ch[cnt]), f[cnt]={fa,c}, tot[cnt]=0, clr(vec[cnt]), cnt; }
//     il void cler() { cnt=0, tot[0]=0;}
//     il void ins1(const string&s, int insx) {
//         int now=cnt?1:newnode(0,0); 
//         for (char c:s) 
//             !ch[now][c-'a']?ch[now][c-'a']=newnode(now, c-'a'), adj[now].push_back(ch[now][c-'a']),1:0, 
//             now=ch[now][c-'a'];
//         vec[now].push_back(insx); 
//     }
//     il void ins2(const string&s, int addx) {
//         int now=cnt?1:newnode(0,0); 
//         for (char c:s) 
//             !ch[now][c-'a']?ch[now][c-'a']=newnode(now, c-'a'),1:0, 
//             now=ch[now][c-'a'];
//         tot[now]+=addx; 
//     }
//     il int get(const string&s) {
//         int now=cnt?1:newnode(0,0);
//         int re=tot[now]; 
//         for (char c:s) 
//             !ch[now][c-'a']?ch[now][c-'a']=newnode(now, c-'a'),1:0, 
//             now=ch[now][c-'a'], re+=tot[now];
//         return re;
//     }
// }