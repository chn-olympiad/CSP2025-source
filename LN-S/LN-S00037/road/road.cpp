#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define qrw ios::sync_with_stdio(0),cin.tie(0)
int n,m,k;
int a[11][10005],c[11];
struct edge{int u,v,w;}adj[5000005];
edge adjj[5000005];
bool cmp(edge a,edge b){return a.w<b.w;}
int fa[10005];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void hb(int x,int y){
    fa[find(x)]=find(y);
}
int kruskal(int aaa){
    int cnt=0,sum=0;
    for(int i=1;i<=m+aaa;i++){
        // cout<<i<<" "<<adj[i].u<<" "<<adj[i].v<<" "<<adj[i].w<<endl;
        if(find(adj[i].u)==find(adj[i].v)) continue;
        hb(adj[i].u,adj[i].v);
        sum+=adj[i].w;
        cnt++;
        if(cnt==n-1) return sum;
    }
    cout<<"???";
    return -1;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    qrw;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[i]={u,v,w};
    }
    sort(adj+1,adj+m+1,cmp);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    int sum=kruskal(0);
    // cout<<sum<<endl;
    for(int i=1;i<=m;i++) adjj[i]=adj[i];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=m;j++) adj[j]=adjj[j];
        for(int j=1;j<=n;j++) fa[j]=j;
        int cnt=0;
        for(int j=1;j<=n;j++){
            for(int l=j+1;l<=n;l++){
                adj[m+(++cnt)]={j,l,a[i][j]+a[i][l]};
            }
        }
        sort(adj+1,adj+m+cnt+1,cmp);
        // cout<<"m:"<<endl;
        // for(int i=1;i<=m+cnt;i++) cout<<i<<" "<<adj[i].u<<" "<<adj[i].v<<" "<<adj[i].w<<endl;
        // cout<<"end"<<endl;
        int summ=kruskal(cnt);
        sum=min(sum,summ+c[i]);
        // cout<<i<<" "<<summ+c[i]<<endl;
    }
    cout<<sum<<endl;
}