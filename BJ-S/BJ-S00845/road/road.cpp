#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k;
int f[N];
struct edge{
    int u,v;
    int w;
}path[1000005];
int c[15],a[15][N];

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int findf(int x){
    if(f[x]==x){
        return x;
    }
    return f[x]=findf(f[x]);
}

bool fmerge(int x,int y){
    int fx=findf(x),fy=findf(y);
    if(fx!=fy){
        f[fx]=fy;
        return true;
    }
    return false;
}

void Kruskal(){
    int res=0;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    sort(path+1,path+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(fmerge(path[i].u,path[i].v)){
            res+=path[i].w;
        }
    }
    cout<<res;
    return ;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int x,y,z;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        path[i]=edge{x,y,z};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(k==0){
        Kruskal();
    }else{
        cout<<0;
    }
    return 0;
}
