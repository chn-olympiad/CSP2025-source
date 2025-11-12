#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,sum,cnt,c[N],fa[N];
struct Node{
    int u,v,w;
    friend bool operator<(Node x,Node y){
        return x.w<y.w;
    }
} e[N];
int find(int x){
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)!=find(v)){
            sum+=w;
            cnt++;
            fa[find(u)]=find(v);
        }
        if(cnt==n-1)
            break;
    }
    cout<<sum<<'\n';
    return 0;
}
// include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+10,inf=0x3f3f3f3f;
// long long n,m,k,sum,cnt,c[N],fa[N];
// long long g[N][N],a[15][N];
// struct Node{
//     long long u,v,w;
//     friend bool operator<(Node x,Node y){
//         return x.w>y.w;
//     }
// } e[N];
// int find(int x){
//     return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
// }
// int main(){
//     // freopen("road3.in","r",stdin);
//     // freopen("road.out","w",stdout);
//     cin>>n>>m>>k;
//     memset(g,0x3f,sizeof(g));
//     for(int i=1;i<=n;i++)
//         fa[i]=i;
//     while(m--){
//         int u,v,w;
//         cin>>u>>v>>w;
//         g[u][v]=g[v][u]=w;
//     }
//     for(int i=1;i<=k;i++){
//         cin>>c[i];
//         for(int j=1;j<=n;j++)
//             cin>>a[i][j];
//     }
//     if(k)
//         for(int i=1;i<=n;i++)
//             for(int j=i+1;j<=n;j++)
//                 for(int w=1;w<=k;w++)
//                     g[i][j]=g[j][i]=min(a[w][i]+a[w][j],g[i][j]);
//     m=0;
//     for(int i=1;i<=n;i++)
//         for(int j=i+1;j<=n;j++)
//             if(g[i][j]!=inf)
//                 e[++m]={i,j,g[i][j]};
//     sort(e+1,e+m+1);
//     for(int i=1;i<=m;i++){
//         int u=e[i].u,v=e[i].v,w=e[i].w;
//         if(find(u)!=find(v)){
//             sum+=w;
//             cnt++;
//             fa[find(u)]=find(v);
//         }
//         if(cnt==n-1)
//             break;
//     }
//     cout<<sum<<'\n';
//     return 0;
// }