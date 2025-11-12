#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
};
node a[100005];
int fa[100005];
bool cmp(node x,node y){
    return x.w<y.w;
}
int getfa(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=getfa(fa[x]);
}
int main (){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(a+1,a+m+1,cmp);
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++){
        int fx=getfa(a[i].u);
        int fy=getfa(a[i].v);
        if(fx!=fy){
            fa[fx]=fy;
            ans+=a[i].w;
            //cout<<a[i].w<<" ";
            cnt++;
            if(cnt==n-1){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    return 0;
}
