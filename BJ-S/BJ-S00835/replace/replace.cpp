#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define reb(i,n) for(int i=0;i<(n);++i)
#define ppct __builtin_popcount
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
#define mkp make_pair
#define hh(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=2e5+20,M=5e6+7,INF=1e18,mod=1e9+7,MOD=998244353,base=131;
double Time(){
    return 1.*clock()/CLOCKS_PER_SEC;
}
bool __st;
void cmin(int&a,int b){
    if(a>b)a=b;
}
namespace AC{
    int32_t tr[M][26],tot=1,ed[M],out[M],fail[M];
    vector<int32_t>G[M];
    void clear(){
        rep(i,tot){
            reb(j,26)tr[i][j]=0;
            ed[i]=0;out[i]=0;
            fail[i]=0;
            G[i].clear();
        }
        tot=1;
    }
    void insert(string s){
        int p=1;
        reb(i,s.size()){
            int x=s[i]-'a';
            if(!tr[p][x]){
                tr[p][x]=++tot;
            }
            p=tr[p][x];
        }
        ed[p]++;
    }
    void build(){
        queue<int>q;q.push(1);
        reb(j,26)tr[0][j]=1;
        while(q.size()){
            int u=q.front();q.pop();
            int fl=fail[u];G[fail[u]].pb(u);
            reb(j,26){
                int v=tr[u][j];
                if(!tr[u][j]){tr[u][j]=tr[fl][j];continue;}
                fail[v]=tr[fl][j];++out[v];q.push(v);
            }
        }
    }
    void gt(){
        queue<int>q;
        rep(i,tot)if(out[i]==0)q.push(i);
        while(q.size()){
            int u=q.front();q.pop();
            // ed[u]+=ed[fail[u]];
            for(int v:G[u]){
                ed[v]+=ed[u];--out[v];
                if(out[v]==0)q.push(v);
            }
        }
    }
}
using namespace AC;
map<pair<pii,pii>,int>mp;
bool __ed;
int ans[N],ct,L[N],R[N];
vector<int32_t>wtf[N],qs[N];
string oo[N],que[N];
int calc(string&s,int L,int R){
    int ans=0,p=1;
    reb(i,s.size()){
        p=tr[p][s[i]-'a'];
        if(i>=R)
        ans+=ed[p];
    }
    p=1;
    hh(i,L+1,s.size()-1){
        p=tr[p][s[i]-'a'];
        if(i>=R)
        ans-=ed[p];
    }
    return ans;
}
int solve(){
    int n,q;
    cin>>n>>q;
    rep(i,n){
        string xx,yy;cin>>xx>>yy;
        int m=xx.size(),be=-1,ed=0;
        reb(i,m){
            if(xx[i]!=yy[i]){
                if(be==-1)be=i;
                ed=i;
            }
        }
        pair<pii,pii> tmp;
        if(be==-1)tmp.X=tmp.Y=mkp(0,0);
        else{
            int Hx=0,Hy=0,HX=0,HY=0;
            hh(i,be,ed){
                Hx=(Hx*base+xx[i])%mod;
                Hy=(Hy*base+yy[i])%mod;
                HX=(HX*base+xx[i])%MOD;
                HY=(HY*base+yy[i])%MOD;
            }
            tmp=mkp(mkp(Hx,HX),mkp(Hy,HY));
        }
        if(mp.find(tmp)==mp.end())mp[tmp]=(++ct);
        wtf[mp[tmp]].pb(i);
        oo[i]=xx;
    }
    rep(i,q){
        string xx,yy;
        cin>>xx>>yy;
        int m=xx.size(),be=-1,ed=0;
        reb(i,m){
            if(xx[i]!=yy[i]){
                if(be==-1)be=i;
                ed=i;
            }
        }
        pair<pii,pii> tmp;
        if(be==-1)tmp.X=tmp.Y=mkp(0,0);
        else{
            int Hx=0,Hy=0,HX=0,HY=0;
            hh(i,be,ed){
                Hx=(Hx*base+xx[i])%mod;
                Hy=(Hy*base+yy[i])%mod;
                HX=(HX*base+xx[i])%MOD;
                HY=(HY*base+yy[i])%MOD;
            }
            tmp=mkp(mkp(Hx,HX),mkp(Hy,HY));
        }
        if(mp.find(tmp)==mp.end())continue;
        qs[mp[tmp]].pb(i);que[i]=xx;
        L[i]=be;R[i]=ed;
    }
    rep(i,ct){
        clear();
        if(!qs[i].size())continue;
        for(int id:wtf[i])
        insert(oo[id]);
        build();gt();
        for(int id:qs[i])
        ans[id]=calc(que[id],L[id],R[id]);
    }
    rep(i,q)cout<<ans[i]<<"\n";
    return 0;
}
main(){
    FILE("replace");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    // cout<<Time()<<"\n";
    return 0;
}
