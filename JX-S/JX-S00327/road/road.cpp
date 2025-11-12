#include<bits/stdc++.h>
using namespace std;
struct FSI{
    template<typename T>
    FSI& operator >> (T&res){
        res=0;T f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
        while(isdigit(ch)){res=(res*10)+(ch-48);ch=getchar();}
        res*=f;
        return *this;
    }
} scan;
typedef long long ll;
const int N=1e4+5,M=1e6+5;
struct node{
    int u,v,w;
    node(){}
    node(int _u,int _v,int _w){u=_u,v=_v,w=_w;}
    friend bool operator < (const node &a,const node &b){
        return a.w<b.w;
    }
} a[M];
int fa[N];
inline void init(int n){
    for(int i=0;i<=n;i++) fa[i]=i;
}
inline int find(int x){
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
int w[15][N];
set<node> ss,s;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
//  2^k times MST, O(mlogm*2^k)/O((n+m)logn*2^k).
//  only the n-1 edges that have been chosen can be changed.//fake
    int n,m,k;
    scan>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scan>>a[i].u>>a[i].v>>a[i].w;
    }
    bool flag=m<=100000;
    sort(a+1,a+m+1);
    init(n);
    ll res=0;
    int cc=0;
    for(int i=1;i<=m;i++){
        if(k!=0&&flag) ss.emplace(a[i]);
        int u=find(a[i].u),v=find(a[i].v);
        if(u!=v){
            res+=a[i].w,fa[u]=v;
            if(k!=0&&!flag) ss.emplace(a[i]);
            if(++cc==n-1) break;
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<=n;j++) scan>>w[i][j];
    }
    ll tmp=0;
    for(int i=1,lim=(1<<k)-1;i<=lim;i++){
        tmp=0,s=ss;
        int cnt=0,cc=0;
        for(int j=i;j;j-=j&-j){
            int p=__builtin_ctz(j);
            cnt++,tmp+=w[p][0];
            for(int t=1;t<=n;t++) s.emplace(t,n+cnt,w[p][t]);
        }
        init(n+cnt);
        for(auto &t:s){
            int u=find(t.u),v=find(t.v);
            if(u!=v){
                tmp+=t.w,fa[u]=v;
                if(++cc==n+cnt-1) break;
            }
        }
        res=min(res,tmp);
    }
    printf("%lld\n",res);
    return 0;
}