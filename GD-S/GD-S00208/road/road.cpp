#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e4;
const int maxm=1e6;
const int maxk=10;
struct Edge{int u,v,w,id;};
int n,m,K;
Edge E[maxm+5];
int c[maxk+5];
int a[maxk+5][maxn+5];
Edge EE[maxm+5];int eet;
int fa[maxn+5];
ll ans,res;
inline bool Cmp(Edge x,Edge y){return x.w<y.w;}
inline int Root(int x){
    if(fa[x]) return fa[x]=Root(fa[x]);
    else return x;
}
inline int Read(){
    char ch=getchar();
    int rs=0;
    for(;ch<'0'||'9'<ch;ch=getchar());
    for(;'0'<=ch&&ch<='9';ch=getchar())
        rs=(rs<<1)+(rs<<3)+ch-'0';
    return rs;
}
signed main(){
    // const double stim=clock();
    freopen("road.in","r",stdin);
    // freopen("road4.in","r",stdin);
    freopen("road.out","w",stdout);
    
    n=Read(),m=Read(),K=Read();
    for(int i=1;i<=m;i++){
        E[i].u=Read(),E[i].v=Read(),E[i].w=Read();
        E[i].id=0;
    }
    for(int i=1;i<=K;i++){
        c[i]=Read();
        a[i][0]=1;
        for(int j=1;j<=n;j++){
            a[i][j]=Read();
            if(a[i][j]<a[i][a[i][0]])
                a[i][0]=j;
        }
        for(int j=1;j<=n;j++){
            if(j!=a[i][0]){
                eet++;
                EE[eet].u=a[i][0];
                EE[eet].v=j;
                EE[eet].w=a[i][j];
                EE[eet].id=i;
            }
        }        
    }
    sort(E+1,E+m+1,Cmp);
    int u,v,ru,rv;
    for(int i=1;i<=m;i++){
        u=E[i].u,v=E[i].v;
        ru=Root(u),rv=Root(v);
        if(ru==rv) continue;
        fa[ru]=rv;
        eet++;
        EE[eet]=E[i];
        ans+=E[i].w;
    }
    sort(EE+1,EE+eet+1,Cmp);
    const int tp=1<<K;
    for(int s=1;s<tp;s++){
        memset(fa,0,sizeof(fa));
        res=0;
        for(int i=1;i<=K;i++)
            if((s>>(i-1))&1)
                res+=c[i]+a[i][a[i][0]];
        for(int i=1;i<=eet;i++){
            if(EE[i].id==0||((s>>(EE[i].id-1))&1)){
                u=EE[i].u,v=EE[i].v;
                ru=Root(u),rv=Root(v);
                if(ru==rv) continue;
                fa[ru]=rv;
                res+=EE[i].w;
            }
        }
        ans=min(ans,res);
    }
    printf("%lld",ans);
    
    // cerr<<endl<<(clock()-stim)/CLOCKS_PER_SEC;
    return 0;
}