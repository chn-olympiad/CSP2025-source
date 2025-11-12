#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v;
    long long w;
}s[1000100];
int n,m,k,len,f[10010],a[15][10010],g[1010][1010];
long long ans;
bool cmp(node x,node y){
    return x.w<y.w;
}
int get(int x){
    if(f[x]!=x){
        f[x]=get(f[x]);
    }
    return f[x];
}
void kruskal(){
    sort(s+1,s+len+1,cmp);
    int cnt=0;
    for(int i=1;i<=len;i++){
        int u=s[i].u,v=s[i].v;
        long long w=s[i].w;
        int fu=get(u),fv=get(v);
        if(fu==fv){
            continue;
        }else{
            f[fv]=fu;
            ans+=w;
            cnt++;
            if(cnt==n-1){
                break;
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=min(g[u][v],w);
        g[v][u]=min(g[v][u],w);
    }
    for(int j=1;j<=k;j++){
        int c,id;
        cin>>c;
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
            if(a[j][i]==0){
                id=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=id){
                g[id][i]=min(g[id][i],a[j][i]);
                g[i][id]=min(g[i][id],a[j][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&g[i][j]<=1e9){
                s[++len]={i,j,g[i][j]};
            }
        }
    }
    kruskal();
    cout<<ans;
    return 0;
}
