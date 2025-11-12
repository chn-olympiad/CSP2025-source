#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u;
    int v;
    int w;
}e[1145141];
int f[11451];
int kk[11][11451],kj[11];
int fd(int x){
    if(f[x]!=x)
        f[x]=fd(f[x]);
    return f[x];
}
bool cmp(edge a,edge b){
    if(a.w<b.w){
        return true;
    }
    return false;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+n+1,cmp);
    for(int i=1;i<=k;i++){
        cin>>kj[i];
        for(int j=1;j<=n;j++){
            scanf("%d",&kk[i][j]);
        }
    }
    int nm1=0,nm2=0;
    for(int i=1;i<=m;i++){
        int aa=fd(e[i].u);
        int bb=fd(e[i].v);
        if(aa!=bb){
            f[aa]=bb;
            nm1++;
            nm2+=e[i].w;
        }
        if(nm1>=n-1){
            break;
        }
    }
    cout<<nm2;
    return 0;
}

