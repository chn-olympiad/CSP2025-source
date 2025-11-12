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
#define ll long long
#define db double
#define ldb long double
#define pct __builtin_popcount
#define pctll __builtin_popcountll
using namespace std;
const int N=15;
int n,m,ans;
int c[N],p[N];
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>s;
    if(s.find('0')==string::npos){
        ll ans=1;
        rept(i,2,n){
            (ans*=i)%=998244353ll;
        }
        cout<<ans<<endl;
        return 0;
    }
    s=" "+s;
    rept(i,1,n) cin>>c[i];
    rept(i,1,n) p[i]=i;
    do{
        int pre=0;
        rept(i,1,n){
            if(pre>=c[p[i]]||s[i]=='0') ++pre;
        }
        ans+=(n-pre)>=m;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans%998244353<<endl;
    return 0;
}

