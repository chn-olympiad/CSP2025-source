#include<iostream>
#include<algorithm>
using namespace std;
const int N=1008;
const int M=2000008;
int n,m,k;
int x,y,z;
int tot=1;
int sol[15][N];
long long ans=0;
struct edge{
    int s;
    int t;
    long long w;
    bool xj;
}e[M];
bool sj[N];
int fee[N];
int uf[N];
void ufc(){
    for(int i=0;i<=n;i++){
        uf[i]=i;
    }
}
int find(int x){
    if(uf[x]!=x){
        uf[x]=find(uf[x]);
    }
    return uf[x];
}
void united(int x,int y){
    uf[find(x)]=find(y);
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
void kruskal(){
    ufc();
    sort(e+1,e+tot,cmp);
    for(int i=1;i<tot;i++){
        if(find(e[i].s)!=find(e[i].t)){
            ans+=e[i].w;
            ans-=fee[e[i].xj];
            if(e[i].xj!=0&&sj[e[i].xj]==0){
                sj[e[i].xj]=1;
                ans+=fee[e[i].xj];
            }
            united(e[i].s,e[i].t);
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        e[tot].s=x;
        e[tot].t=y;
        e[tot].w=z;
        e[tot].xj=0;
        tot++;
    }
    for(int i=1;i<=k;i++){
        cin>>fee[i];
        for(int j=1;j<=n;j++){
            cin>>sol[i][j];
            //if(i!=j){
            for(int k=1;k<j;k++){
                e[tot].s=k;
                e[tot].t=j;
                e[tot].w=fee[i]+sol[i][j]+sol[i][k];
                e[tot].xj=i;
                tot++;
            }
            //}
        }
    }
    kruskal();
    cout<<ans;
}
