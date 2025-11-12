#include<bits/stdc++.h> 
bool Mbe;
using namespace std;
#define il inline
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define fi first
#define se second 
typedef array<int,3> ai3;
const int MAXN=500, mod=998244353;
template<typename t1> il bool cmax(t1&x, const t1&y) { return x<y?x=y,1:0; }
template<typename t1> il bool cmin(t1&x, const t1&y) { return y<x?x=y,1:0; }
il ll Mod(ll x) {return (x%mod+mod)%mod; }
#define sz(x) ((int)x.size())
int n, m; string s; int a[MAXN+3];
struct S1 { // n<=10
    int id[MAXN+3], tot, ans;;
    il void solve() {
        ans=0; for (int i=1; i<=n; ++i) id[i]=i; 
        do {
            tot=0;
            for (int i=1; i<=n; ++i) tot+=s[i]&&(i-1-tot<a[id[i]]);
            ans+=(tot>=m);
        } while (next_permutation(id+1, id+1+n) );
        cout << Mod(ans);
    }
}; 
struct S2 { // n==m;
    il void solve(ll ans=0) {
        sort(a+1, a+1+n);
        for (int i=n; i>=1; --i) {
            // (ans*=lower_bound(a+1, a+1+n, i)-a - (n-i) )%=mod;
            // ans*=s[i];
            (ans*=s[i]&&a[i]?i:0)%=mod;
        }
        cout << Mod(ans);
    }
}; 
il void solve() {
    cin >> n >> m >> s, s=" "+s; 
    for (int i=1; i<=n; ++i) cin >> a[i], s[i]^='0';
    if (n<=10) return (new S1)->solve();
    if (n==m)  return (new S2)->solve();
    cout << 0;
}
db Tbe; bool Men;
int main() {
#ifdef MYFRE
    Tbe=clock();
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
    solve();
    // int t; cin >> t; while (t--) solve();
#ifdef MYFRE
    cerr << "M: " << (&Mbe-&Men)/1024.0/1024 << " T: " <<  (clock()-Tbe)/1e6 << endl;
#endif
}
