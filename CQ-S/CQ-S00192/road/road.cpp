#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define popcount __builtin_popcount
using namespace std;
int rd(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f*=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(ch-'0');
    return x*f;
}
const int N=1e4+20,INF=0x3f3f3f3f;
int c[N],n,K,m;
struct node{
    int u,v,w;
    friend bool operator<(const node &x,const node &y){return x.w<y.w;}
};
vector<node> e;
node vec[11][N];
struct DSU{
    int fa[N],siz[N];
    int find(int u){return (fa[u]==u)?u:fa[u]=find(fa[u]);}
    void init(int lim){
        for(int i=1;i<=lim;i++)fa[i]=i,siz[i]=1;
    }
    void merge(int u,int v){
        if(siz[u]<siz[v]) fa[u]=v,siz[v]+=siz[u];
        else fa[v]=u,siz[u]+=siz[v];
    }
}T;
priority_queue<pair<int,pii> > q;
int siz[12];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=rd(),m=rd(),K=rd();
    for(int i=1;i<=m;i++){
        int u=rd(),v=rd(),w=rd();
        e.p_b((node){u,v,w});
    }
    sort(e.begin(),e.end());T.init(n);
    ll ans=0;
    int fu,fv;
    for(auto [u,v,w] : e){
        fu=T.find(u),fv=T.find(v);
        if(fu!=fv)ans+=w,T.merge(fu,fv),vec[0][siz[0]++]=(node){u,v,w};
    }
    reverse(vec[0],vec[0]+siz[0]);
    for(int i=1;i<=K;i++){
        c[i]=rd();
        for(int j=1;j<=n;j++){
            int w=rd();
            vec[i][siz[i]++]=(node){i+n,j,w};
        }
        sort(vec[i],vec[i]+siz[i]);
        reverse(vec[i],vec[i]+siz[i]);
    }
    for(int sta=1;sta<(1<<K);sta++){
        while(!q.empty())q.pop();
        for(int i=0;i<=K;i++)if(i==0||((sta>>(i-1))&1)){
            if(siz[i]) q.push(m_p(-vec[i][siz[i]-1].w,m_p(i,siz[i]-1)));
        }
        int need=n-1;ll res=0;
        for(int i=0;i<K;i++) if((sta>>i)&1)res+=c[i+1],need++;
        T.init(n+K);
        while(need&&res<ans){
            auto [id,i]=q.top().se;q.pop();
            auto [u,v,w]=vec[id][i];
            fu=T.find(u),fv=T.find(v);
            if(fu!=fv)res+=w,T.merge(fu,fv),need--;
            if(i) q.push(m_p(-vec[id][i-1].w,m_p(id,i-1)));
        }
        ans=min(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}
//g++ road.cpp -o road -std=c++14 -O2 -Wall -fsanitize=address,undefined