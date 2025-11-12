#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1e4+5,M=2e6+5;

struct Edge{
    int u,v,w;
}ed[12][M],tmp[M];
int len[12],c[12];

int fa[M];

int getfa(const int &u){
    if(fa[u]==u)return u;
    return fa[u]=getfa(fa[u]);
}

void merge(const int &x,const int &y){
    int fx=getfa(x),fy=getfa(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}

void init(int maxn){
    for(int i=0;i<=maxn;i++){
        fa[i]=i;
    }
}

int n,m,k;

bool cmp(Edge x,Edge y){
    return x.w<y.w;
}

long long f(Edge *e,int len){
    sort(e+1,e+1+len,cmp);
    init(n+k+2);
    long long res=0;
    for(int i=1;i<=len;++i){
        if(getfa(e[i].u)!=getfa(e[i].v)){
            // cout<<e[i].u<<" "<<e[i].v<<endl;
            merge(e[i].u,e[i].v);
            res+=e[i].w;
        }
    }
    return res;
}

void inputEdge(){
    for(int i=1;i<=m;++i){
        cin>>tmp[i].u>>tmp[i].v>>tmp[i].w;
    }
    sort(tmp+1,tmp+1+m,cmp);
    init(n+2);
    for(int i=1;i<=m;i++){
        if(getfa(tmp[i].u)!=getfa(tmp[i].v)){
            merge(tmp[i].u,tmp[i].v);
            ed[0][++len[0]]=Edge{tmp[i].u,tmp[i].v,tmp[i].w};
        }
    }
}

Edge edge[M];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    inputEdge();
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;cin>>w;
            ed[i][++len[i]]=Edge{i+n,j,w};
        }
    }
    long long ans=9e18;
    for(int i=0;i<1<<k;++i){
        int l=0;
        long long res=0;
        for(int j=1;j<=k;++j){
            if(i&(1<<j-1)){
                res+=c[j];
                for(int k=1;k<=len[j];++k){
                    edge[++l]=ed[j][k];
                }
            }
        }
        for(int j=1;j<=len[0];++j){
            edge[++l]=ed[0][j];
        }
        // for(int j=1;j<=l;j++){
            // cout<<edge[j].u<<edge[j].v<<edge[j].w<<"\t";
        // }
        // cout<<endl;
        res+=f(edge,l);
        // cout<<res<<endl;
        ans=min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}