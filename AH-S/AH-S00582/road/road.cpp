#include<bits/stdc++.h>
using namespace std;
#define sp putchar(' ')
#define el putchar('\n')
using ll=__int128;
inline ll read(){
    ll ans=0;
    int f=1;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        ans=(ans<<1)+(ans<<3)+(cc^'0');
    }while(isdigit(cc=getchar()));
    return ans*f;
}
inline void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x+'0');
    }else{
        print(x/10);
        putchar(x%10+'0');
    }
}
const int N=10005;
int n,m,k;
bool flaga=1;
vector<array<int,2>>g[N+20];
int c[N],a[20][N];
vector<array<int,3>>e;
int pre[N+20];
inline int find(int x){
    if(pre[x]==0){
        return x;
    }
    return pre[x]=find(pre[x]);
}
inline void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        pre[x]=y;
    }
}
ll kruskal(){
    ll ans=0;
    sort(e.begin(),e.end());
    for(auto[w,u,v]:e){
        if(find(u)!=find(v)){
            merge(u,v);
            ans+=w;
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1,u,v,w;i<=m;++i){
        u=read();
        v=read();
        w=read();
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        e.push_back({w,u,v});
    }
    for(int i=1;i<=k;++i){
        c[i]=read();
        if(c[i]){
            flaga=0;
        }
        for(int j=1;j<=n;++j){
            a[i][j]=read();
            if(a[i]){
                flaga=0;
            }
        }
    }
    if(flaga){
        for(int i=1;i<=k;++i){
            for(int j=1;j<=n;++j){
                e.push_back({a[i][j],n+i,j});
            }
        }
        print(kruskal());
    }else{
        print(kruskal());
    }
    el;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
