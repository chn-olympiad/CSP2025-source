#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=2e6+5;
const int M=1e4+5;
int n,m,k,U[N],V[N],W[N],C,f[M],fa[M],cur,c[M],a[20][M];
struct node{
    ll u,v,w;
    bool operator <(node B){
        return w<B.w;
    }
}G[N];
int fr(int now){
    return fa[now]==now?now:fa[now]=fr(fa[now]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k; cur=n;
    for(int i=1;i<=m;i++){
        cin>>G[i].u>>G[i].v>>G[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    ll minn=1e16;
    ll curb=m,curd=n,ans=0;
    for(int j=1;j<=k;j++){
        curd++;
        for(int l=1;l<=n;l++){
            G[++curb].u=curd;
            G[curb].v=l,G[curb].w=a[j][l];
        }
    }
    for(int j=1;j<=curd;j++)fa[j]=j;
    for(int j=1;j<=n;j++)f[j]=1;
    for(int j=n;j<=curd;j++)f[j]=0;
    sort(G+1,G+curb+1);
    for(int j=1;j<=curb;j++){
        if(f[1]==n)break;
        int _u=min(G[j].u,G[j].v);
        int _v=max(G[j].u,G[j].v);
        int ufa=fr(_u),vfa=fr(_v);
        if(ufa!=vfa){
            ans+=G[j].w;
            fa[vfa]=ufa;
            f[ufa]+=f[vfa];
        }
    }
    minn=min(minn,ans);
    cout<<minn;
    return 0;
}