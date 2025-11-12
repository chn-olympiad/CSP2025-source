#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000006],fa[1000006];
struct node{
    int u,v,w;
}t[1000006];
bool cmp(node x,node y){
    return x.w<y.w;
}
int findrt(int x){
    if(fa[x]==x) return x;
    return fa[x]=findrt(fa[x]);
}
void unionn(int x,int y){
    int fx=findrt(x);
    int fy=findrt(y);
    if(fx!=fy) fa[fx]=fy;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=n;i++) fa[i]=i;
        long long ans=0;
        for(int i=1;i<=m;i++) cin>>t[i].u>>t[i].v>>t[i].w;
        sort(t+1,t+m+1,cmp);
        for(int i=1;i<=m;i++){
            if(findrt(t[i].u)!=findrt(t[i].v)){
                unionn(t[i].u,t[i].v);
                ans+=t[i].w;
            }
        }
        cout<<ans;
    }else{
        cout<<0;
    }
    return 0;
}
