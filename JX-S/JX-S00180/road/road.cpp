#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node{
    int u,v,w;
}b[N];
int n,m,k,idx,ans,fa[N];
int c[N],a[N][N];
int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        b[++idx]={u,v,w};
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(c[i]==0) b[++idx]={i,j,a[i][j]};
        }
    }
    sort(b+1,b+1+idx,cmp);
    int cnt=0;
    for(int i=1;i<=idx;i++){
        int u=b[i].u,v=b[i].v,w=b[i].w;
        if(find(fa[u])==find(fa[v])) continue;
        fa[u]=find(fa[v]);
        ans+=w;
        cnt++;
        if(cnt==n-1) break;
    }
    cout<<ans;
    return 0;
}