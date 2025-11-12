#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,c,b[12][1010],num,ans,f[1010];
bool vis[1010],d[1010][1010];
struct gzc{
    int v,c;
};
struct czg{
    int u,v,c;
};
bool operator<(const czg a,czg b){
    return a.c>b.c;
}
int find(int a){
    if(f[a]==a)
        return a;
    return f[a]=find(f[a]);
}
void merge(int a,int b){
    f[find(a)]=find(b);
}
vector<gzc> a[1010];
priority_queue<czg> pq;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        f[i]=i;
    for(int i=1; i<=m; i++){
        cin>>u>>v>>c;
        a[u].push_back({v,c});
        pq.push({u,v,c});
    }
    for(int i=1; i<=k; i++)
    for(int j=0; j<=n; j++){
        cin>>b[i][j];
    }
    bool z=1;
    for(int i=1; i<=k; i++)
        if(b[i][0]>0)
            z=0;
    if(z&&k){

        return 0;
    }
    while(pq.size()){
        czg g=pq.top();
        pq.pop();
        if(find(g.u)!=find(g.v)){
            merge(g.u,g.v);
            vis[g.u]=1;
            vis[g.v]=1;
            d[g.u][g.v]=1;
            d[g.v][g.u]=1;
            ans+=g.c;
        }
    }
        cout<<ans;
    return 0;
}
/*4 4 0
1 4 6
2 3 7
4 2 5
4 3 4*/
