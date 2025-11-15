#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
int fa[maxn],vis[maxn];
int a[25][maxn],c[maxn];
struct node{
    int u,v,w;
};
int n,m,k;
vector<node>g;
bool cmp(node x,node y){
    return x.w<y.w;
}
int find(int u){
    if(u==fa[u])return u;
    return fa[u]=find(fa[u]);
}
void merge(int u,int v){
    fa[find(u)]=find(v);
}

int kruskal(){
    sort(g.begin(),g.end(),cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    int cnt=0,res=0;
    for(auto[u,v,w]:g){
        if(find(u)!=find(v)){
            if(v>n&&!vis[v])vis[v]=1,w+=c[v];
            cnt++;merge(u,v);res+=w;
        }
        if(cnt==n-1)break;
    }
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        g.push_back({u,v,w});
    }
    for(int j=1;j<=k;j++){
        cin>>c[j+n];
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
        }
    }
    cout<<kruskal();
    cout.flush();
    fclose(stdin);fclose(stdout);
    return 0;
    
}
