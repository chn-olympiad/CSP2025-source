#include<bits/stdc++.h>
#define CSP2025 using
#define RP namespace
#define plusplus std
CSP2025 RP plusplus;
#define int long long
#define pii pair<int,int>
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
const int N=1e4+5,M=2e6+5;
int bcj[N];
struct edge{int u,v,w;}e[M];
bool cmp(edge x,edge y){return x.w<y.w;}
void init_bcj(int v){for(int i=1;i<=v;++i)bcj[i]=i;}
int find_bcj(int x){return x==bcj[x]?x:bcj[x]=find_bcj(bcj[x]);}
void merge_bcj(int x,int y){bcj[find_bcj(x)]=find_bcj(y);}
bool same_bcj(int x,int y){return find_bcj(x)==find_bcj(y);}
int U[M],V[M],W[M],n,m,k,c[15][N];
int kruskal(int n,int m){
    int ans=0;
    init_bcj(n);
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;++i){
        int u=e[i].u,v=e[i].v,d=e[i].w;
        if(!same_bcj(u,v))merge_bcj(u,v),ans+=d;
    }return ans;
}signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=rd(),m=rd(),k=rd();
    int ans=LLONG_MAX;
    for(int i=1;i<=m;++i)U[i]=rd(),V[i]=rd(),W[i]=rd();
    for(int i=1;i<=k;++i)for(int j=0;j<=n;++j)c[i][j]=rd();
    for(int p=0;p<(1<<k);++p){
        int _n=n,_m=m,_p=p,_ans=0;
        for(int i=1;i<=m;++i)e[i]={U[i],V[i],W[i]};
        for(int i=1;i<=k;++i){
            if(_p&1){
                ++_n,_ans+=c[i][0];
                for(int j=1;j<=n;++j)e[++_m]={_n,j,c[i][j]};
            }_p>>=1;
        }//debug(p);
        //cout<<_n<<' '<<_m<<'\n';
        //for(int i=1;i<=_m;++i)cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
        _ans+=kruskal(_n,_m);
        ans=min(ans,_ans);
    }cout<<ans<<'\n';
}
/*
5 10 0
1 2 7
1 3 9
1 4 1
1 5 3
2 3 2
2 4 8
2 5 6
3 4 10
3 5 5
4 5 4
*/
