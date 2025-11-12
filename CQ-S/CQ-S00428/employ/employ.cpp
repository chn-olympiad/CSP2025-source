#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define repl(i,x,y) for(register int i=(x);i<(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define fir first
#define sec second
#define pub push_back
#define pob pop_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double flt;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define put(x) cout<<(x)<<"\n"
#define file(f) freopen(#f".in","r",stdin);freopen(#f".out","w",stdout);

const int N=505,mod=998244353;

int n,m;
int s[N],c[N];

int p[N];
int ans;

inline void Main(){
    cin>>n>>m;
    rep(i,1,n){
        char ch;cin>>ch;
        s[i]=ch-'0';
    }
    rep(i,1,n)cin>>c[i];
        rep(i,1,n)p[i]=i;
        do{
            int cnt=0;
            rep(i,1,n){
                int x=p[i];
                if(!s[i]||cnt>=c[x])++cnt;
            }
            if(n-cnt>=m)++ans;
        }while(next_permutation(p+1,p+1+n));
        put(ans);
}
int main(){
    file(employ);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(16);
    Main();
    return 0;
}