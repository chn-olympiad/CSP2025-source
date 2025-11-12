#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int K=11;
int n,m,k,ans;
int c[K],a[K][N],idk[K],idn[N];
int fa[N];
map<int,vector<int>>mp;
struct Edge{
    signed u,v,w;
}e[M];
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-48);ch=getchar();}
    return x*f;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int p,int q,int val){
    int cost=val;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(find(j)==q) cost=min(cost,a[i][j]);
        }
    }
    ans+=cost;
    fa[q]=p;
}
void kruskal(){
    sort(e+1,e+m+1,[](const auto&A,const auto& B){return A.w<B.w;});
    int tot=0;
    for(int i=1;i<=m;i++){
        int p=find(e[i].u),q=find(e[i].v);
        if(p==q) continue;
        if(k==0) fa[q]=p,ans+=e[i].w;
        else merge(p,q,e[i].w);
        tot++;
        if(tot==n-1){
            break;
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        e[i].u=read();
        e[i].v=read();
        e[i].w=read();
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
    kruskal();
    cout<<ans;
    return 0;
}
