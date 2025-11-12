#include<bits/stdc++.h>
using namespace std;
const int N=10015;
const int K=15;
int n,m,k;
__int128 c[N];
__int128 a[K][N];
struct edge{
    int u,v;
    __int128 w;
};
vector<edge>V;
int father[N];
__int128 read(){
    long long K;
    scanf("%lld",&K);
    return __int128(K);
}
void print(__int128 K){
    if(K<0){
        print(0-K);
        return;
    }
    if(K/10!=0)print(K/10);
    printf("%d",K%10);
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int root(int x){
    if(x==father[x]){
        return x;
    }
    return father[x]=root(father[x]);
}
void Merge(int u,int v){
    father[root(u)]=root(v);
}
__int128 Kruskal(){
    __int128 turn=0;
    for(edge e:V){
        int u=e.u,v=e.v;
        __int128 w=e.w;
        if(root(u)!=root(v)){
            Merge(u,v);
            turn+=w;
        }
    }
    return turn;
}
bool choose[K];
vector<edge>G;
__int128 Kruskall(){
    G=V;
    __int128 turn=0;
    for(int i=1;i<=n+k;i++){
        father[i]=i;
    }
    for(int i=1;i<=k;i++){
        if(choose[i]){
            turn+=c[i];
            for(int j=1;j<=n;j++){
                G.push_back({i+n,j,a[i][j]});
            }
        }
    }
    sort(G.begin(),G.end(),cmp);
    for(edge e:G){
        int u=e.u,v=e.v;
        __int128 w=e.w;
        if(root(u)!=root(v)){
            Merge(u,v);
            turn+=w;
        }
    }
    return turn;
}
__int128 DFS(int chose,int step){
    choose[step]=chose;
    if(step==k){
        return Kruskall();
    }
    else{
        return min(DFS(0,step+1),DFS(1,step+1));
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        __int128 w;
        scanf("%d%d",&u,&v);
        w=read();
        V.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",c+i);
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
    if(k==0){
        sort(V.begin(),V.end(),cmp);
        for(int i=1;i<=n;i++){
            father[i]=i;
        }
        print(Kruskal());
    }
    else{
        sort(V.begin(),V.end(),cmp);
        for(int i=1;i<=n;i++){
            father[i]=i;
        }
        print(DFS(0,0));
    }
    return 0;
}
