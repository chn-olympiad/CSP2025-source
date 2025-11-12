#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,tot,ans,fa[20005];
struct node{
    int u,v,w;
}e[7000005];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
void kruscal(){
    sort(e+1,e+tot+1,cmp);
    int cnt=0;
    for(int i=1;i<=tot;i++){
        int u=e[i].u;
        int v=e[i].v;
        u=find(u);
        v=find(v);
        if(u==v) continue;
        fa[fa[v]]=fa[u];
        ans+=e[i].w;
        cnt++;
        if(cnt==n-1) break;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e[++tot].u=x;
        e[tot].v=y;
        e[tot].w=z;
        e[++tot].u=y;
        e[tot].v=x;
        e[tot].w=z;
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            int p;
            cin>>p;
            e[++tot].u=i;
            e[tot].v=j;
            e[tot].w=p+c;
            e[++tot].u=j;
            e[tot].v=i;
            e[tot].w=p+c;
        }
    }
    kruscal();
    cout<<ans;
    return 0;
}
