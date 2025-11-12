#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
    int u,v,w;
}e[N];
int n,m,k;
int cnt;
bool cmp(node x,node y){
    return x.w<y.w;
}
vector<node> G[N];
int f[N];
void init(){
    for(int i=1;i<=n+k;i++){
        f[i]=i;
    }
}
int find(int a){
    if(f[a]==a)return a;
    return f[a]=find(f[a]);
}
void merge(int a,int b){
    int u=find(a),v=find(b);
    if(u==v)return;
    f[u]=v;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
        cnt++;
    }
    for(int i=1;i<=k;i++){
        int c;cin>>c;
        for(int i=1;i<=n;i++){
            int w;cin>>w;
            cnt++;
            e[cnt].u=n+i;
            e[cnt].v=i;
            e[cnt].w=w;
        }
    }
    init();
    sort(e+1,e+1+cnt,cmp);
    int ans=0;
    for(int i=1;i<=cnt;i++){
        int u=e[i].u,v=e[i].v;
        if(find(u)==find(v))continue;
        ans+=e[i].w;
        merge(u,v);
    }
    cout<<ans<<"\n";
    return 0;
}
