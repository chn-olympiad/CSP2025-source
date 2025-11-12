#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define ll long long
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define pre(i,n) for(int i = n;i;--i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define debug cout<<"Help"<<endl
#define swp(x,y) (x ^= y ^= x ^= y)
bool St;
constexpr int N = 1e5 + 5;
int a[N][3],b[N],T,n,u,tot,ans;
vector <int> vec[3];
inline void solve(){
    vec[0].clear(),vec[1].clear(),vec[2].clear();
    cin>>n,ans = 0;
    rep(i,n){
        u = 0;
        rpt(j,0,2){
            cin>>a[i][j];
            if(a[i][j] > a[i][u]) u = j;
        }
        vec[u].emplace_back(i),ans += a[i][u];
    }
    u = 0;
    rep(i,2) if(vec[i].size() > vec[u].size()) u = i;
    if(vec[u].size() <= n / 2) return cout<<ans<<'\n',void();
    tot = 0;
    for(auto i : vec[u]){
        int mx = 0;
        rpt(j,0,2) if(j ^ u) mx = max(mx,a[i][j]);
        b[++tot] = a[i][u] - mx;
    }
    sort(b + 1,b + tot + 1);
    rep(i,(int)vec[u].size() - n / 2) ans -= b[i];
    cout<<ans<<'\n';
}
bool En;
int main(){
//    fin("club5.in"),fout("club.out");
    fin("club.in"),fout("club.out");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--) solve();
    cerr<<'\n'<<clock() * 1.0 / CLOCKS_PER_SEC;
    cerr<<'\n'<<(&En - &St) / 1024.0 / 1024;
    return 0;
}
//Ren5Jie4Di4Ling5%
