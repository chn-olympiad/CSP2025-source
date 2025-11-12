#include <bits/stdc++.h>

using namespace std;

#define int long long

#define fileio(x,y) freopen(x,"r",stdin),freopen(y,"w",stdout);
#define tup tuple<int,int,int>
#define fir(x) (get<0>(x))
#define sec(x) (get<1>(x))
#define thr(x) (get<2>(x))
#define pii pair<int,int>
#define bit(x) bitset<x>
#define pb emplace_back
#define i12 __int128_t
#define mt make_tuple
#define ll long long
#define mp make_pair

const int   mod1=998244853,mod2=1e9+7;
const int   base1=31,base2=37;
const int   mod=998244353;

const char  emp=(char)('a'-1);
const int   maxm=5e6+10;
const int   maxn=2e5+10;

typedef pair<pii,pii> ty;

map<ty,int> id,ext[maxn];
int         hl[maxm],hr[maxm];
int         n,m,tot;

pii load(string &x)
{
    int v1=0,v2=0;
    for(char it:x)
        // v2=(v2*base2+it-'a')%mod2,
        v1=(v1*base1+it-'a')%mod1;
    return mp(x.size(),v1);
}

void work()
{
    /* Code */
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        string s,t; cin>>s>>t;
        int l=0,r=s.size()-1;
        while(s[l]==t[l]) l++;
        while(s[r]==t[r]) r--;
        if(l>r) continue;
        string vs="",vt="",ls="",rs="";
        for(int j=l; j<=r; j++) vs+=s[j],vt+=t[j];
        for(int j=l-1; j>-1; j--) ls+=s[j];
        for(int j=r+1; j<s.size(); j++) rs+=s[j];
        // cerr<<vs<<'!'<<vt<<'!'<<ls<<'!'<<rs<<'\n';
        ty h(load(vs),load(vt));
        if(!id.count(h)) id[h]=++tot;
        ext[id[h]][mp(load(ls),load(rs))]++;
    }
    for(int i=1; i<=m; i++)
    {
        string s,t; cin>>s>>t;
        if(s.size()!=t.size()) { cout<<0<<'\n'; continue; }
        int l=0,r=s.size()-1,tar=0;
        while(s[l]==t[l]) l++;
        while(s[r]==t[r]) r--;
        string vs="",vt="",ls="",rs="";
        for(int j=l; j<=r; j++) vs+=s[j],vt+=t[j];
        for(int j=l-1; j>-1; j--) ls+=s[j],hl[l-j]=(hl[l-j-1]*base1+s[j]-'a')%mod1;
        for(int j=r+1; j<s.size(); j++) rs+=s[j],hr[j-r]=(hr[j-r-1]*base1+s[j]-'a')%mod1;
        // cerr<<vs<<'!'<<vt<<'!'<<ls<<'!'<<rs<<'\n';
        ty h1(load(vs),load(vt)); int ii=id[h1];
        for(auto [it,val]:ext[id[h1]])
        {
            pii left=fir(it),right=sec(it);
            if(ls.size()<fir(left)) continue;
            if(rs.size()<fir(right)) continue;
            if(hl[fir(left)]!=sec(left)) continue;
            if(hr[fir(right)]!=sec(right)) continue;
            tar+=val;
        }
        cout<<tar<<'\n';
    }
    return;
}

signed main()
{
    fileio("replace.in","replace.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) work();
    return 0;
} // Cellinia Texas.
