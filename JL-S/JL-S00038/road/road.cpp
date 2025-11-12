#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100000,M=2000010;
int n,m,k;
int p[N];
int ans;
struct Edge{
    int u,v,w;
}edge[M];
int mfind(int x){
    if(p[x]!=x) p[x]=mfind(p[x]);
    return p[x];
}
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int getn(int i,int j){
    return m+(i-1)*n+j;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edge[i]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        int c;
        scanf("%lld",&c);
        for(int j=1;j<=n;j++){
            int a;
            scanf("%lld",&a);
            edge[getn(i,j)]={i+n,j,a};
        }
    }
    m=getn(k,n);
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;i++){
        int pa=mfind(edge[i].u),pb=mfind(edge[i].v),w=edge[i].w;
        if(pa!=pb){
            p[pa]=pb;
            ans+=w;
        }
    }
    cout<<ans;
    return 0;
}
