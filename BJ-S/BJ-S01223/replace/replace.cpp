// Will I win? - 15:12
#include <bits/stdc++.h>
#define rep(i,a,b,c)    for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c)    for(int i=(a);i>=(b);i-=(c))
#define pb push_back
#define pii pair<int,int>
#define vint vector<int>

using namespace std;

const int mod=998244353;
bool Mbe;
const int maxm=4.02e5;
const int maxn=5.02e6;
const int inf=1e9;

inline int fpow(int x,int y){
    int r=1;
    for(;y;x=x*x%mod,y>>=1) if(y&1) (r*=x)%=mod;
    return r;
}inline int inv(int x){ return fpow(x,mod-2);}

//Must stop at 17:00
pii ia[maxm];
struct BIT{
    int num[maxm],n;
    inline int lb(int p){   return p&(-p);}
    void padd(int p,int v){
        while(p<=n){
            num[p]+=v;p+=lb(p);
        }
    }
    int qsum(int p){
        int ans=0;
        while(p)    ans+=num[p],p-=lb(p);
        return ans;
    }
}bi;
struct ACAM{
    int ch[maxn][26],fail[maxn],cc=0;bool ok[maxn];int dis[maxn],bdis[maxm];
    vint adj[maxn];
    int ins(string s,int id){
        int u=0;
        for(auto c:s){
            c-='a';
            if(!ch[u][c])   ch[u][c]=++cc;
            dis[ch[u][c]]=dis[u]+1;u=ch[u][c];
        }
        ok[u]=1;return u;
    }
    int dfn[maxn],dt,sz[maxm],bel[maxn];bool in[maxn];
    vint gr[maxn];int cn=0;
    void dfs(int u){
        int su=(ok[u]?inf:0);
        // cerr<<"!!!"<<u<<" "<<ok[u]<<endl;
        for(auto v:adj[u]){        
            dfs(v);
            su+=ok[v];ok[u]|=ok[v];
        }
        if(su>1 || !u){
            // cerr<<"tot"<<u<<endl;
            in[u]=1;if(u)   bel[u]=++cn,bdis[cn]=dis[u];
            for(auto v:adj[u])  if(ok[v]){
               gr[bel[u]].pb(bel[v]);
            }
        }else if(ok[u]) for(auto v:adj[u])  bel[u]|=bel[v];
    }
    void dfs2(int u){
        for(auto v:adj[u]){
            if(!in[v])  bel[v]=bel[u];
            dfs2(v);
        }
    }
    void dfs3(int u){
        sz[u]=1;dfn[u]=++dt;
        for(auto v:gr[u]){
            // cerr<<"w"<<u<<" "<<v<<endl;
            dfs3(v);sz[u]+=sz[v];
        }
    }
    void build(){
        queue<int> q;
        rep(i,0,25,1)   if(ch[0][i])    q.push(ch[0][i]);
        while(!q.empty()){
            int u=q.front();q.pop();
            rep(c,0,25,1){
                if(ch[u][c])    fail[ch[u][c]]=ch[fail[u]][c],q.push(ch[u][c]);
                else            ch[u][c]=ch[fail[u]][c];
            }
        }
        rep(i,1,cc,1)   adj[fail[i]].pb(i);
        dfs(0);dfs2(0);dfs3(0);
    }
}sa,ta;
vector<array<int,3>> qu[maxm];
vint s2t[maxm];
int st[maxm],tp;

void calc(int u){
    st[++tp]=u;
    // cerr<<"!!!
    for(auto [li,v,id]:qu[u])   if(id>0){
        int l=1,r=tp,pt=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(sa.bdis[st[mid]]<li)      pt=st[mid],l=mid+1;
            else                        r=mid-1;
        }
        if(pt)  qu[pt].pb({li,v,-id});
    }
    for(auto v:sa.gr[u])    calc(v);
    tp--;
}int ans[maxm];

void cal2(int u){
    for(auto v:s2t[u])  bi.padd(ta.dfn[v],1),bi.padd(ta.dfn[v]+ta.sz[v],-1);//cerr<<"www"<<ta.dfn[v]<<" "<<ta.dfn[v]+ta.sz[v]<<endl;;
    for(auto [li,v,id]:qu[u]){
        if(id>0)    ans[id]+=bi.qsum(ta.dfn[v]);
        else        ans[-id]-=bi.qsum(ta.dfn[v]);
    }
    for(auto v:sa.gr[u])    cal2(v);
    for(auto v:s2t[u])  bi.padd(ta.dfn[v],-1),bi.padd(ta.dfn[v]+ta.sz[v],1);//cerr<<"rem"<<ta.dfn[v]<<" "<<ta.dfn[v]+ta.sz[v]<<endl;;
}


bool Med;
signed main(){ios::sync_with_stdio(0);cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    rep(i,1,n,1){
        string s,t;cin>>s>>t;
        ia[i]={sa.ins(s,i),ta.ins(t,i)};
    }
    sa.build();ta.build();
    bi.n=ta.cn+100;
    rep(i,1,n,1){
        s2t[sa.bel[ia[i].first]].pb(ta.bel[ia[i].second]);
    }  
    rep(id,1,q,1){
        string s1,s2;cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            ans[id]=0;continue ;
        }
        // cerr<<"Meow"<<endl;
        int u=0,v=0,m=s1.size()-1,l=m+1,r=0;
        rep(i,0,m,1)    if(s1[i]!=s2[i])    {l=i;break ;}
        per(i,m,0,1)    if(s1[i]!=s2[i])    {r=i;break ;}
        rep(i,0,m,1){
            u=sa.ch[u][s1[i]-'a'],v=ta.ch[v][s2[i]-'a'];
            if(i>=r){
                if(sa.bdis[sa.bel[u]]>=i-l+1 && ta.bdis[ta.bel[v]]>=i-l+1)    qu[sa.bel[u]].pb({max(0,i-l+1),ta.bel[v],id});
            }
        }
    }
    // return 0;
    calc(0);cal2(0);
    rep(i,1,q,1)    cout<<ans[i]<<'\n';
    return 0;
}