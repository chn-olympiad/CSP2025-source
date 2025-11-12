#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20010,M = 1000010;
int n,m,k;
struct node{
    int u;
    int v;
    int w;
}e[M<<1];
int idx = 0;
int f[N];
inline int find(int x){
    if(f[x]==x)return x;
    else return f[x] = find(f[x]);
}
bool cmp(node a,node b){
    return a.w<b.w;
}
int ans = 0;
void kruskal(){
    sort(e+1,e+idx+1,cmp);
    for(int i = 1;i<=idx;i++){
        int x = e[i].u,y = e[i].v,val = e[i].w;
        if(find(x)==find(y)){
            continue;
        }
        ans+=val;
        f[find(x)] = find(y);
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1;i<=n+k;i++){
        f[i] = i;
    }
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[++idx] = {u,v,w};
    }
    for(int i = 1;i<=k;i++){
        int c;
        cin>>c;
        ans+=c;
        for(int j = 1;j<=n;j++){
            cin>>c;
            e[++idx] = {n+i,j,c};
        }
    }
    n+=k;
    kruskal();
    cout<<ans<<"\n";
    return 0;
}
