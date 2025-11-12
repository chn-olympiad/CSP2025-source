#include <bits/stdc++.h>
using namespace std;
namespace Light_Tea{
    void Main();
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    Light_Tea::Main();
    return 0;
}
namespace Light_Tea{
    using i64 = long long;

    constexpr int kM=1e6+5, kN=1e4+5;

    int n,m,k,c[12],a[12][kN];
    i64 tot_ans=0;

    struct Edge{
        int u,v,w;
        friend bool operator < (const Edge &A,const Edge &B){
            return A.w<B.w;
        }
    }e[kM],ne[kN*11];
    int ne_cnt;

    struct BCJ{
        int bel[kN+10],siz[kN+10];
        void init(){
            for(int i=1; i<=n+k; i++) bel[i]=i, siz[i]=1;
        }
        int find(int x){
            return (bel[x]==x)?(x):(bel[x]=find(bel[x]));
        }
        void merge(int x,int y){
            x=find(x), y=find(y);
            if(x!=y){
                if(siz[x]<siz[y]) swap(x,y);
                bel[y]=x, siz[x]+=siz[y];
            }
        }
        bool adj(int x,int y){
            return find(x)==find(y);
        }
    }S;

    void Main(){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1; i<=m; i++){
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        for(int i=1; i<=k; i++){
            scanf("%d",&c[i]);
            for(int j=1; j<=n; j++){
                scanf("%d",&a[i][j]);
                ne[++ne_cnt]=Edge{n+i,j,a[i][j]};
            }
        }

        sort(e+1,e+m+1);

        S.init();
        for(int i=1; i<=m; i++) if(!S.adj(e[i].u,e[i].v)){
            ne[++ne_cnt]=e[i], tot_ans+=e[i].w;
            S.merge(e[i].u,e[i].v);
        }

        sort(ne+1,ne+ne_cnt+1);

        for(int s=0; s<(1<<k); s++){
            S.init();

            i64 res=0;
            int cnt=0, nd=n;
            for(int i=1; i<=k; i++) if(s&(1<<(i-1))) res+=c[i], nd++;

            for(int i=1; i<=ne_cnt; i++){
                if(ne[i].u>n){
                    int x=ne[i].u-n;
                    if(!(s&(1<<(x-1)))) continue;
                }

                if(!S.adj(ne[i].u,ne[i].v)){
                    res+=ne[i].w, S.merge(ne[i].u,ne[i].v), cnt++;
                    if(res>=tot_ans) break;
                    if(cnt==nd-1) break;
                }
            }

            tot_ans=min(tot_ans,res);
        }

        printf("%lld\n",tot_ans);
    }
}