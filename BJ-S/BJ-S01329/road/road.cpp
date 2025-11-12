#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e9+5;
int n,m,k,idx=0,res=0;
LL c[N],f[N][N];
LL graph[N][N];
struct node{
    int u,v,w;
}a[N];
void dijkstra(int u,int v){
    int INF=INT_MAX;
    graph[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int i=1;i<=m;i++){

        }
    }
}
int main(){
    freopen("road","r",stdin);
    freopen("road","w",stdout);
    cin>>n>>m>>k;
    dijkstra(1,1);
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            cin>>c[j]>>f[j][i];
        }
    }
    cout<<res<<endl;
    return 0;
}