// Will I win? - 14:22
#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c)    for(int (i)=(a);i<=(b);i+=(c))
#define per(i,a,b,c)    for(int (i)=(a);i>=(b);i-=(c))
#define pb push_back
#define pii pair<int,int>

using namespace std;

const int mod=998244353;
bool Mbe;
const int maxn=1.2e5;

inline int fpow(int x,int y){
    int r=1;
    for(;y;x=x*x%mod,y>>=1) if(y&1) (r*=x)%=mod;
    return r;
}inline int inv(int x){ return fpow(x,mod-2);}

int a[maxn][3],cho[maxn];
int cc[3];

void solve(){
    int ans=0;int n;cin>>n;
    cc[0]=cc[1]=cc[2]=0;
    rep(i,1,n,1)    rep(j,0,2,1)    cin>>a[i][j];
    rep(i,1,n,1){
        int v=max({a[i][0],a[i][1],a[i][2]});
        ans+=v;
        if(v==a[i][0])  cc[0]++,cho[i]=0;
        else if(v==a[i][1]) cc[1]++,cho[i]=1;
        else                cc[2]++,cho[i]=2;
    }
    int id=-1;
    rep(i,0,2,1)    if(cc[i]>n/2)   id=i;
    if(id==-1)  return cout<<ans<<'\n',void(0);
    priority_queue<int,vector<int>,greater<int>> pq;
    rep(i,1,n,1)    if(cho[i]==id){
        int t=2e9;
        rep(j,0,2,1)    if(j!=id)   t=min(t,a[i][id]-a[i][j]);
        pq.push(t);
    }
    while(pq.size()>n/2)    ans-=pq.top(),pq.pop();
    cout<<ans<<'\n';
}

bool Med;
signed main(){ios::sync_with_stdio(0);cin.tie(0);cerr<<"Used:"<<fixed<<setprecision(2)<<(&Mbe-&Med)/1048576.0<<"MiB\n";
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--)  solve();
    return 0;
}