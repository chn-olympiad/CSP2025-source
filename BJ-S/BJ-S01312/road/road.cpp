#include<bits/stdc++.h>
using namespace std;
void read(int &k){
    int f=1;k=0;char c=getchar_unlocked();
    while(c<='0'||c>='9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        k=(k<<3)+(k<<1)+c-'0';
        c=getchar_unlocked();
    }
    k*=f;
}
int n,m,k,fa[10005],c[15],v[15][10005];
struct edge {
    int u,v,w;
}e[1000005];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    fa[x]=find(y);
}
int kruskal(){
    sort(e+1,e+n+1,[](edge x,edge y){return x.w<y.w;});
    int ans=0,tot=0;
    for(int i=1;i<=m;++i){
        if(find(e[i].u)!=find(e[i].v)) merge(e[i].u,e[i].v),ans+=e[i].w;
        tot++;
        if(tot==n-1) break;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j){
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        fa[i]=i;
    }
    if(k==0){
        cout<<kruskal();
    }
    return 0;
}
