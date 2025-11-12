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
#define mp make_pair

const int   mod=998244353;
const int   maxn=1e5+10;

vector<tup> res[3];
tup         a[maxn];
int         n;

void work()
{
    /* Code */
    cin>>n; int tar=0;
    res[0].clear(),res[1].clear(),res[2].clear();
    for(int i=1,x,y,z; i<=n; i++) cin>>x>>y>>z,a[i]=mt(x,y,z);
    for(int i=1; i<=n; i++)
    {
        int val=max({fir(a[i]),sec(a[i]),thr(a[i])});
        if(fir(a[i])==val) res[0].pb(a[i]);
        else if(sec(a[i])==val) res[1].pb(a[i]);
        else if(thr(a[i])==val) res[2].pb(a[i]);
    }
    sort(res[0].begin(),res[0].end(),[](tup x,tup y){
        return max(sec(x),thr(x))-fir(x)<max(sec(y),thr(y))-fir(y);
    });
    sort(res[1].begin(),res[1].end(),[](tup x,tup y){
        return max(fir(x),thr(x))-sec(x)<max(fir(y),thr(y))-sec(y);
    });
    sort(res[2].begin(),res[2].end(),[](tup x,tup y){
        return max(sec(x),fir(x))-thr(x)<max(sec(y),fir(y))-thr(y);
    });
    // cerr<<res[0].size()<<' '<<res[1].size()<<' '<<res[2].size()<<'\n';
    while(res[0].size()>n/2)
    {
        tup val=res[0].back(); res[0].pop_back();
        if(sec(val)>=thr(val)) res[1].pb(val); else res[2].pb(val);
    }
    while(res[1].size()>n/2)
    {
        tup val=res[1].back(); res[1].pop_back();
        if(fir(val)>=thr(val)) res[0].pb(val); else res[2].pb(val);
    }
    while(res[2].size()>n/2)
    {
        tup val=res[2].back(); res[2].pop_back();
        if(sec(val)>=fir(val)) res[1].pb(val); else res[0].pb(val);
    }
    for(auto [x,y,z]:res[0]) tar+=x;
    for(auto [x,y,z]:res[1]) tar+=y;
    for(auto [x,y,z]:res[2]) tar+=z;
    cout<<tar<<'\n';
    return;
}

signed main()
{
    fileio("club.in","club.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) work();
    return 0;
} // Cellinia Texas.