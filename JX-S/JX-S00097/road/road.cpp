#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e4+10;
int n,m,k;
int c[15][N];
struct node{
   int u,v,w;
}a[10*N];
int fa[N];
ll ans;
int find(int x){
    if(fa[x]!=x) return fa[x]=find(fa[x]);
    return fa[x];
}
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    IOS
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int cnt=0;
    for(int i=1;i<=m;i++){
        cnt++;
        cin>>a[cnt].u>>a[cnt].v>>a[cnt].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i][0];
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(u!=v){
                    cnt++;
                    a[cnt].u=u;
                    a[cnt].v=v;
                    a[cnt].w=c[u][v]+c[v][u];
                }
            }
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }

    for(int i=1;i<=cnt;i++){
        int u=a[i].u,v=a[i].v,w=a[i].w;
        if(v<u){
            swap(u,v);
        }
        int x=find(u),y=find(v);
        if(x!=y){
            fa[x]=y;
            ans+=w;
        }
    }
    cout<<ans;

    return 0;
}
/*
4 6 1
1 2 1
1 2 2
2 3 1
4 3 1
3 2 2
1 4 1
0 0 0 0 0


*/
