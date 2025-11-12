#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
const int N=1e+4+5,M=1e+6+5,K=15;
int n,m,k,tot;
long long int ans;
struct edge{
    int u,v,w;
    bool operator<(const edge &b){
        return this->w<b.w;
    }
};
array<edge,M+N*K> road;
array<int,N+10> fa;
array<bool,N+10> vis;
array<int,K> c;
array<array<int, N>, K> a;
inline void init(){
    for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
    return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void merge(int a,int b){
    fa[find(a)]=find(b);
}
inline void kru(){
    for(int i=0;i<m&&tot!=n;i++){
        if(find(road[i].u)!=find(road[i].v)){
            merge(road[i].u,road[i].v);
            if(!vis[road[i].u]){
                if(road[i].u<=n)
                    tot++;
                vis[road[i].u]=1;
            }
            if(!vis[road[i].v]){
                if(road[i].v<=n)
                    tot++;
                vis[road[i].v]=1;
            }
            ans+=road[i].w;
        }
    }
}
int main(void){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=0;i<m;i++)
        cin>>road[i].u>>road[i].v>>road[i].w;
    for(int j=0;j<k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
        }
    }
    sort(road.begin(),road.begin()+m);
    kru();
    cout<<ans;
    return 0;
}