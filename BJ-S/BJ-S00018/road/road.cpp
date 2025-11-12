#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans,fa[10010];
struct node{
    int u,v,w;
}a[1000010];
bool cmp(node x,node y){
    return x.w<y.w;
}
int find(int x){
    if(x==fa[x]){
        return x;
    }
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+m+1,cmp);
    if(k==0){
        for(int i=1;i<=m;i++){
            if(find(a[i].u)!=find(a[i].v)){
                merge(a[i].u,a[i].v);
                ans+=a[i].w;
            }
        }
        cout<<ans;
    }else{
        cout<<0;
    }
    return 0;
}
