#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
void in(T &x){
    char c=getchar(); int f=1; x=0;
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x*=f;
}
const int N=10020,M=1000010,K=12;
const ll oo=0x3f3f3f3f3f3f3f3f;
int lowbit(int x){return x&-x;}
int n,m,k;
struct Edge{
    int u,v,w;
    bool operator<(const Edge &a){
        return w<a.w;
    }
}a[M],b[K][N],c[1030][N<<1]; int len[1030]; ll pc[1030];
struct DSU{
    int fa[N];
    void init(int n){
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int find(int x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    bool merge(int x,int y){
        x=find(x); y=find(y);
        if(x==y) return 0;
        fa[x]=y; return 1;
    }
}dsu;
ll kruskal(Edge *a,int len,int &newlen){
    dsu.init(n+k+2);
    ll res=0; newlen=0;
    for(int i=1;i<=len;i++){
        if(dsu.merge(a[i].u,a[i].v)){
            // printf("%d ",i);
            res+=a[i].w;
            a[++newlen]=a[i];
        }
    }
    // printf("%lld\n",res);
    return res;
}
int cost[K];
ll ans=oo;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    in(n); in(m); in(k);
    for(int i=1;i<=m;i++)
        in(a[i].u),in(a[i].v),in(a[i].w);
    sort(a+1,a+m+1);
    for(int i=1;i<=k;i++){
        in(cost[i]);
        for(int j=1;j<=n;j++){
            b[i][j].u=n+i; b[i][j].v=j;
            in(b[i][j].w);
        }
        sort(b[i]+1,b[i]+n+1);
    }
    ans=min(ans,kruskal(a,m,len[0]));
    for(int i=1;i<=len[0];i++)
        c[0][i]=a[i];
    for(int i=1;i<(1<<k);i++){
        int pre=i^lowbit(i),pos=__lg(lowbit(i))+1;
        // printf("%d %d %d\n",i,pre,pos);
        len[i]=len[pre]; pc[i]=pc[pre]+cost[pos];
        for(int j=1;j<=len[i];j++)
            c[i][j]=c[pre][j];
        for(int j=1;j<=n;j++)
            c[i][len[i]+j]=b[pos][j];
        sort(c[i]+1,c[i]+len[i]+n);
        ans=min(ans,kruskal(c[i],len[pre]+n,len[i])+pc[i]);
    }
    printf("%lld",ans);
    return 0;
}