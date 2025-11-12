#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10,maxm=1e6+10;
int n,m,k;
int e[maxn][maxn],ans;
pair<int,pair<int,int>>w[maxm];
long long c[20],a[20][maxn];
bool vis[maxn];
void dfs(int u){
    vis[u]=true;
    for(int v=1;v<=n;v++){
        if(e[u][v] && !vis[v])dfs(v);
    }
}
bool connect(int st,int ed){
    for(int i=0;i<=n;i++)vis[i]=0;
    dfs(st);
    return vis[ed];
}
int main(){
    freopen("road3.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        w[i]={wt,{u,v}};
    }
    sort(w+1,w+n+1);
    int top=1;
    for(int i=0;i<n-1;i++){
        int u,v,wt;
        wt=w[top].first;
        u=w[top].second.first;
        v=w[top].second.second;
        if(!connect(u,v)){
            e[u][v]=wt;
            e[v][u]=wt;
            ans+=wt;
        }
        top++;
        cout<<u<<' '<<v<<' '<<wt<<'\n';
    }
    cout<<ans;
    return 0;
}
