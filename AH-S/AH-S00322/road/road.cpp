#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int fa[10005];
struct node{
    int x,y,z;
}e[10005];
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int check(int x){
    if(fa[x]!=x){
        return fa[x]=check(fa[x]);
    }
    return x;
}
bool cmp(node x,node y){
    return x.z<y.z;
}
void kk(){
    init();
   sort(e+1,e+m+1,cmp);
   for(int i=1;i<=m;i++){
        int xx=check(e[i].x);
        int yy=check(e[i].y);
        if(xx!=yy){
            fa[yy]=xx;
            ans+=e[i].z;
        }
   }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=m;i++){
            cin>>e[i].x>>e[i].y>>e[i].z;
        }
        kk();
        cout<<ans;
    }
    return 0;
}
