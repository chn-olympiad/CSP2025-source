#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int u,v,w;
};
vector<node>e;
bool cmp(node x,node y){
    return x.w<y.w;
}
int fa[10005];
int get(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=get(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    sort(e.begin(),e.end(),cmp);
    int sum=n,ans=0;
    for(int i=0;i<e.size();i++){
        int u=e[i].u;
        int v=e[i].v;
        int w=e[i].w;
        int fu=get(u);
        int fv=get(v);
        if(fu!=fv){
            fa[fu]=fv;
            ans+=w;
                if(--sum==1){
                    break;
                }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}