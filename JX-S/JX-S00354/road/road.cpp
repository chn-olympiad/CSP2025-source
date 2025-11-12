#include<bits/stdc++.h>
#define ll long long
const int N=2e6+100;
using namespace std;
ll T,n,m,q,tot=0;
ll a[N],ans=0;
ll fa[N],d[N];

int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }

struct E{ int u,v,w; }ed[N];
void add(int u,int v,int w){ ed[++tot]=E{u,v,w}; }

int cmp(E x,E y){ return x.w<y.w; }

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1,u,v,w;i<=m;++i){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    int sc=n;
    for(int i=1,w;i<=q;++i){
        scanf("%d",&w);
        for(int j=1;j<=n;++j){
            scanf("%lld",&d[j]);
            for(int k=1;k<j;++k)
                add(j,k,d[j]+d[k]);
        }
    }
    sort(ed+1,ed+1+tot,cmp);
    for(int i=1;i<=tot;++i){
        int p=find(ed[i].u);
        int q=find(ed[i].v);
        if(p==q) continue;
        fa[p]=q; sc--;
        ans+=ed[i].w;
        if(sc==1) break;
    }
    printf("%lld\n",ans);
    return 0;
}
