#include<bits/stdc++.h>
using namespace std;
int fa[100010];
int n,m,k;
int ans;
struct node{
    int u,v,w;
}a[100010];
int fnd(int k){
    if(fa[k]==k) return k;
    return fnd(fa[k])==fnd(k);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=100009;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
        if(a[i].u>a[i].v){
            swap(a[i].u,a[i].v);
        }
    }
    for(int i=1;i<=m;i++){
        if(fa[fnd(a[i].u)]!=fa[fnd(a[i].v)]){
            ans+=a[i].w;
            //fa[a[i].u]=a[i].v;
        }
    }
    cout<<ans;
    return 0;
}
// what???
// i'm so nooob
// pls 20pts and more
// i don't like dij
// i forget it
// T_T
// tot pts:20/0+20+40+8=88/68
// shit ,what a suck code

