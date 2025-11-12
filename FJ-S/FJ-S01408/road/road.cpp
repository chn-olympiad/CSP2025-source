#include<bits/stdc++.h>
#define reg register
#define int long long
inline int read(){
    reg int x=0,k=1; reg char ch=getchar();
    while (ch<'0'||ch>'9') (ch=='-')&&(k=-1),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*k; 
}
inline int min(reg int x,reg int y){return x<y?x:y;}
inline int max(reg int x,reg int y){return x>y?x:y;}
inline bool cmax(reg int &x,reg int y){return x<y?x=y,1:0;}
inline bool cmin(reg int &x,reg int y){return x>y?x=y,1:0;}
const int N=2e4+10,M=1e6+20,INF=1e18;
struct EDGE{int u,v,w;}e[M],ee[12][N];
int n,m,K,cnt;
int fa[N],f[N][1<<10|5],c[12],a[12][N],mn[N],sum[1<<10|5];
int find(reg int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dc(reg int L,reg int R,reg int S,std::vector<EDGE> &now){
    if (L>R) return;
    std::vector<EDGE> res;
    if (L==R){
        if (L==0||(S>>L-1&1)){
            for (reg int i=1;i<=n;i++) now.push_back(ee[L][i]); 
        }
        return;
    }
    std::vector<EDGE> A,B; reg int mid=L+R>>1,cc=0;
    for (reg int i=L;i<=R;i++) if (i==0||(S>>i-1&1)) cc++;
    if (!cc) return;
    if (cc==1){
        for (reg int i=L;i<=R;i++) if (i==0||(S>>i-1&1)){
            dc(i,i,S,now);
            return;
        }
    }
    cc=(cc+1)/2;
    // std::cerr<<"<< "<<L<<" "<<R<<"\n";
    for (reg int i=L;i<=R;i++){
        if (i==0||(S>>i-1&1)) cc--;
        if (cc==0) mid=i;
    }
    dc(L,mid,S,A),dc(mid+1,R,S,B);
    if (A.empty()){std::swap(now,B); return;}
    if (B.empty()){std::swap(now,A); return;}
    reg int i=0,j=0;
    while (i<A.size()&&j<B.size()){
        if (A[i].w<B[j].w) now.push_back(A[i++]);
        else now.push_back(B[j++]);
    }
    while (i<A.size()) now.push_back(A[i++]);
    while (j<B.size()) now.push_back(B[j++]);
}
signed main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    n=read(),m=read(),K=read();
    for (reg int i=1;i<=m;i++){
        e[i].u=read(),e[i].v=read(),e[i].w=read();
    }
    for (reg int i=1;i<=K;i++){
        c[i]=read(); 
        for (reg int j=1;j<=n;j++) a[i][j]=read(),ee[i][j]={n+i,j,a[i][j]};
        std::sort(ee[i]+1,ee[i]+n+1,[&](reg EDGE A,reg EDGE B){return A.w<B.w;});
    }
    std::sort(e+1,e+m+1,[&](reg EDGE A,reg EDGE B){return A.w<B.w;});
    reg int ans=0;
    for (reg int i=1;i<=n;i++) fa[i]=i;
    for (reg int i=1;i<=m;i++){
        reg int u=find(e[i].u),v=find(e[i].v);
        if (u!=v) ans+=e[i].w,fa[u]=v,ee[0][++cnt]=e[i];
    }
    for (reg int s=1;s<1<<K;s++){
        // std::cerr<<"<< "<<s<<"\n";
        std::vector<EDGE> qwq;
        for (reg int i=1;i<=n+K;i++) fa[i]=i;
        dc(0,K,s,qwq);
        reg int tot=0,S=0,pc=0;
        for (reg int i=1;i<=K;i++) if (s>>i-1&1) pc++,S+=c[i];
        if (S>ans) continue;
        for (auto [u,v,w]:qwq){
            u=find(u),v=find(v); 
            if (u!=v){
                fa[u]=v,S+=w;
                if (S>ans) break;
            }
            if (tot==n+pc-1) break;
        }
        cmin(ans,S);
    }
    printf("%lld\n",ans);
    return 0;
}