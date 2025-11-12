#include<bits/stdc++.h>
#define int long long 
#define rep(i,x,y) for(int i=x;i<=y;i++) 
#define pb push_back

using namespace std;

int n,m,k;
struct bcj{
    int fa[1145141];
    void init(int n) {
        rep(i,1,n) fa[i]=i;
    }
    int find(int x) {
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    bool same(int x,int y) {
        return find(x)==find(y);
    }
    void hb(int x,int y) {
        x=find(x),y=find(y);
        if(y!=x) fa[y]=x;
    }
}B;
struct node{
    int v,w;
};
vector<node>G[514141];
struct edge{
    int u,v,w;
};
bool cmp(edge x,edge y) {
    return x.w<y.w;
}
int read() {
    int res=0,fs=1;
    char c=getchar();
    while(!(c>='0'&&c<='9')) {
        if(c=='-') fs=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        res=res*10+c-'0';
        c=getchar();
    }
    return res*fs;
}
edge a[2020022],b[2100222];
// int u[1010101],v[2020202],w[2020202];
vector<edge>h,hh;
int ans=0;
int cal(int zs) {
    // cout<<"round\n";
    int na=0;
    // n+=zs;
    B.init(n+k);
    sort(hh.begin(),hh.end(),cmp);
    int id1=0,id2=0;
    int sz1=h.size(),sz2=hh.size();
    int nc=zs;
    while(id1<sz1||id2<sz2) {
        if(id1==sz1){
            //zhinengxuan sz2
            int u=hh[id2].u,v=hh[id2].v,w=hh[id2].w;
            id2++;
            if(B.same(u,v)) continue;
            B.hb(u,v);
            nc--;
            // cout<<"choose"<<u<<' '<<v<<' '<<w<<endl;
            na+=w;
        } else if(id2==sz2) {
            int u=h[id1].u,v=h[id1].v,w=h[id1].w;
            id1++;
            if(B.same(u,v)) continue;
            B.hb(u,v);
            nc--;
            na+=w;
        } else {
            int u,v,w;
            if(h[id1].w>hh[id2].w) u=hh[id2].u,v=hh[id2].v,w=hh[id2].w,id2++;
            else u=h[id1].u,v=h[id1].v,w=h[id1].w,id1++;

            if(B.same(u,v)) continue;
            B.hb(u,v);
            nc--;
            na+=w;

        }
    }
 // cout<<nc<<'\n'; 
    // n-=zs;
    return na;
}
int A[101][10001];
int c[10001];
signed main() {
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    rep(i,1,m) {
        //cin>>a[i].u>>a[i].v>>a[i].w;
         a[i].u=read(),a[i].v=read(),a[i].w=read();
       // G[u[i]].pb({v[i],w[i]});
       // G[v[i]].pb({u[i],w[i]});
    }
    rep(i,1,k){
        cin>>c[i];
        rep(j,1,n) cin>>A[i][j];
    }
    sort(a+1,a+m+1,cmp);
    B.init(n);
    ans=(1ll<<55);
    rep(i,1,m) {
        int u=a[i].u,v=a[i].v,w=a[i].w;
        if(B.same(u,v)) continue;
        B.hb(u,v);
        h.pb({u,v,w});
    }
  //  cout<<h.size()<<'\n';
//h xianzai de bian
    for(int i=0;i<(1ll<<k);i++) {
        hh.clear();
        int jn=0;
        int zs=n;
        rep(u,1,k) {
            if(i&(1ll<<u-1)) jn+=c[u],zs++;
            rep(v,1,n) { 
                if(i&(1ll<<u-1))
                    hh.pb({u+n,v,A[u][v]}); 
            }
        }
        ans=min(ans,cal(zs)+jn);
        // if(cal)
       // cout<<i<<' '<<jn<<'\n';
        // if(cal(zs)+jn==504898585) cout<<i<<endl;
        // break;
    }
    cout<<ans;
    return 0;
}