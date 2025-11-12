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

const int N=1e5+5;

int n;
ll a[N][5];
int rk[N][5];
priority_queue<pli> pq[4];
int cnt[4];
ll ans;
bool vis[N][4];

inline void ins(int x,int k=1){
    int j,to;
    rep(i,1,3)if(!vis[x][i]){
        j=i;
        to=rk[x][i];
        vis[x][i]=1;
        break;
    }
    ans+=a[x][to];
    pq[to].push({a[x][rk[x][j+1]]-a[x][to],x});
    ++cnt[to];
    if(cnt[to]>n/2){
        auto tp=pq[to].top();pq[to].pop();
        // cerr<<x<<"->"<<tp.sec<<"\n";
        --cnt[to];
        ans-=a[tp.sec][to];
        ins(tp.sec,0);
    }
}

inline void Main(){
    cin>>n;
    ans=0;
    rep(i,1,n)rep(j,1,3)vis[i][j]=0;
    rep(i,1,3){
        while(pq[i].size())pq[i].pop();
        cnt[i]=0;
    }
    rep(i,1,n){
        a[i][0]=-1e16;
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        rep(j,1,3)rk[i][j]=j;
        sort(rk[i]+1,rk[i]+1+3,[&](int x,int y){return a[i][x]>a[i][y];});
        // rep(j,1,3)cerr<<rk[i][j]<<" ";cerr<<"\n";
    }
    rep(i,1,n){
        ins(i);
        // cerr<<ans<<"\n";
    }
    // rep(i,1,3){
    //     cerr<<i<<":\n";
    //     while(pq[i].size())cerr<<pq[i].top().sec<<" ",pq[i].pop();
    //     cerr<<"\n";
    // }
    put(ans);
}
int main(){
    file(club);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(16);
    int t;cin>>t;while(t--)Main();
    return 0;
}