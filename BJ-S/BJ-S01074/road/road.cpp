#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0;
struct node1{
    long long v,w;
};
struct node2{
    long long u,v,w;
};
node2 a[1100005];
vector<node1> e[11005];
long long fa[10005],c[15][11005],vis[15],ji[15];
long long find(long long x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
priority_queue<pair<long long,long long> > q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        a[i].u=u;
        a[i].v=v;
        a[i].w=w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        q.push({-w,i});
    }
    long long cnt=m;
    for(long long i=1;i<=k;i++){
        cin>>c[i][0];
        for(long long j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][0]==0){
                a[++cnt].u=j;
                a[cnt].v=m+i;
                a[cnt].w=c[i][j];
                e[j].push_back({m+i,c[i][j]});
                e[m+i].push_back({j,c[i][j]});
            }
        }
    }
    for(long long i=1;i<=n;i++){
        fa[i]=i;
    }
    while(!q.empty()){
        long long x=q.top().second;
        q.pop();
        long long q=find(a[x].u),p=find(a[x].v);
        if(q!=p){
            fa[q]=fa[p];
            if(a[x].v<=m){
                ans+=a[x].w;
            }else{
                vis[a[x].v-m]++;
                ji[a[x].v-m]+=a[x].w;
            }

        }
    }
    for(int i=1;i<=k;i++){
        if(vis[k]>=2){
            ans+=ji[k];
        }
    }
    cout<<ans;
    return 0;
}
