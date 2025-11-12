#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,m,k;
struct node{
    int u,v;
    ll w;
    bool operator<(const node &a){return w<a.w;}
}edge[1000002];
int fa[10002];
ll val;
// vector<pair<int,ll> > a[10012];
// int dep[10012],ace[10012][15];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void kuls();
// void dfs(int x,int fa);

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)   scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    kuls();
    // dfs(1,0);
    printf("%lld",k?0:val);
    return 0;
}

void kuls(){
    for(int i=1;i<=n;i++)   fa[i]=i;
    sort(edge+1,edge+m+1);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(find(edge[i].u)==find(edge[i].v))    continue;
        fa[find(edge[i].u)]=find(edge[i].v);
        // a[edge[i].u].push_back({edge[i].v,edge[i].w});
        // a[edge[i].v].push_back({edge[i].u,edge[i].w});
        val+=edge[i].w;
    }
}

// void dfs(int x,int fa){
//     dep[x]=dep[fa]+1;
//     ace[x][0]=fa;
//     for(int i=1;i<15;i++)   ace[x][i]=ace[ace[x][i-1]][i-1];
//     for(auto i:a[x]){
//         if(i.first==fa) continue;
//         dfs(i.first,x);
//     }
// }