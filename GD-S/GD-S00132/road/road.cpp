#include<bits/stdc++.h>
#define int long long
#define FILE(str) freopen(str".in","r",stdin),freopen(str".out","w",stdout)
inline void read(int &x){
    x=0;int f(1);
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    x=x*f;
}
#define pb push_back
using vi=std::vector <int>;
using pii=std::pair <int,int>;
const int MAXN=1e4+100,MAXM=2e6+5;
int n,m,k;
int fa[MAXN];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void Union(int x,int y){
    x=find(x),y=find(y);
    fa[x]=y;
}
std::set <std::array <int,4> > edge;
int a[15][MAXN],c[15];
int cnt[15],cost[15];
int ans;
inline void Kruscal(){
    while(edge.size()){
        auto it=edge.begin();
        int w=(*it)[0],u=(*it)[2],v=(*it)[3],opt=(*it)[1];
        edge.erase(edge.begin());  
        if(find(u)==find(v)) continue;
        ans+=w,Union(u,v);
        if(opt&&!cnt[opt]){
            cost[opt]=w;
            for(int i=1;i<=n;i++) edge.insert({a[opt][i],opt,u,i});
        }
        if(opt) ++cnt[opt];
    }
}
signed main(){
    FILE("road");
    read(n),read(m),read(k);
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;read(u),read(v),read(w);
        edge.insert({w,0,u,v});
    }
    for(int i=1;i<=k;i++){
        read(c[i]);
        for(int j=1;j<=n;j++){
            read(a[i][j]);
            edge.insert({c[i]+a[i][j],i,i+n,j});
        }
    }
    Kruscal();
    for(int i=1;i<=k;i++) if(cnt[i]==1) ans-=cost[i];
    printf("%lld\n",ans);
}