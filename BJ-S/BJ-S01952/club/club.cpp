#include <bits/stdc++.h>
#define rept(i,a,b) for(int i(a);i<=(b);++i)
#define rep(i,a,b) for(int i(a);i<(b);++i)
#define pert(i,a,b) for(int i(a);i>=(b);--i)
#define per(i,a,b) for(int i(a);i>(b);--i)
#define lowbit(x) ((x)&-(x))
#define ls(p) ((p)<<1)
#define rs(p) ((p)<<1|1)
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
#define umap unordered_map
#define uset unordered_set
#define mmap multimap
#define mset multiset
#define int long long
#define db double
#define ldb long double
#define pct __builtin_popcount
#define pctll __builtin_popcountll
using namespace std;
const int N=2e5;
struct Mod{
    int id,wei;
}m[N*5];
inline bool cmp(const Mod &x,const Mod &y){
    return x.wei>y.wei;
}
int w[N][5],id[N],cnt[5];
bool f[N];
int n,tot,ans;
void solve(){
    memset(cnt,0,sizeof(cnt));
    memset(id,0,sizeof(id));
    memset(f,false,sizeof(f));
    tot=ans=0;
    cin>>n;
    rept(i,1,n){
        rept(j,1,3){
            cin>>w[i][j];
        }
    }
    rept(i,1,n){
        id[i]=1;
        rept(j,2,3){
            if(w[i][j]>w[i][id[i]]) id[i]=j;
        }
        ++cnt[id[i]];
        ans+=w[i][id[i]];
    }
    int crit=0;
    if(cnt[1]>n/2) crit=1;
    else if(cnt[2]>n/2) crit=2;
    else if(cnt[3]>n/2) crit=3;
    if(crit){
        rept(i,1,n){
            if(id[i]!=crit) continue;
            rept(j,1,3){
                if(j==crit) continue;
                m[++tot]={i,w[i][j]-w[i][crit]};
            }
        }
        sort(m+1,m+tot+1,cmp);
        int lst=cnt[crit]-n/2;
        rept(i,1,tot){
            int id=m[i].id,wei=m[i].wei;
            if(!f[id]){
                f[id]=true;
                ans+=wei;
                --lst;
            }
            if(lst<=0) break;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}


