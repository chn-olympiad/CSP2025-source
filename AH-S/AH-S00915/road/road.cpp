#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
struct node{
    int u,v,w;
}r[1000005];
int c[10005],a[15][10005];
bool cmp(node x,node y){
    return x.w<y.w;
}
int fa[10005],cost;
int find(int k){
    if(fa[k]==k) return k;
    return fa[k]=find(fa[k]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>r[i].u>>r[i].v>>r[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    sort(r+1,r+1+m,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(find(fa[r[i].u])!=find(fa[r[i].v])){
            cost+=r[i].w;
            cnt++;
            if(cnt==n-1) break;
            fa[r[i].u]=fa[r[i].v];
        }
    }
    cout<<cost;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
