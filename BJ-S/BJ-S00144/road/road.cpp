#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,k;
struct eg{
    int u,v,w;
};
eg e[1000005];
int fa[10005];
bool cmp(eg i,eg j){
    return i.w<j.w;
}
int gf(int x){
    if(fa[x]==x) return x;
    fa[x]=gf(fa[x]);
    return fa[x];
}
void mg(int x,int y){
    fa[gf(x)]=fa[gf(y)];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e,e+m,cmp);
    int cnt=0,sum=0;
    for(int i=0;i<m;i++){
        if(gf(e[i].u)!=gf(e[i].v)){
            sum++;
            cnt+=e[i].w;
            mg(e[i].u,e[i].v);
        }
        if(sum==n-1) break;
    }
    cout<<cnt;
    return 0;
}
