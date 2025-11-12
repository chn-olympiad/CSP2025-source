#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e5+15,M=1e6+5;
struct edge{ int u,v,w; } e[N];
int tot;
int c[N],a[11][N];
int F[N];
int find(int u){ return u==F[u]?u:F[u]=find(F[u]); }
void join(int u,int v){ if(find(u)!=find(v)) F[find(u)]=find(v); }
bool cmp(edge u,edge v){ return u.w<v.w; }
void solveA(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            e[++tot]=edge{n+i,j,a[i][j]};
        }
    }
    sort(e+1,e+m+1,cmp);
    int cnt=0,sum=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        int su=find(u),sv=find(v);
        if(su==sv) continue;
        else {
            cnt++;
            sum+=e[i].w;
            join(u,v);
        }
        if(cnt==n-1) break;
    }
    cout<<sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool A=true;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=n;i++) F[i]=i;
    for(int i=1;i<=k;i++) {
        cin>>c[i]; A&=(c[i]==0);
        for(int j=1;j<=n;j++) cin>>a[i][j],A&=(a[i][j]==0);
    }
    sort(e+1,e+m+1,cmp);
    int cnt=0,sum=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        int su=find(u),sv=find(v);
        if(su==sv) continue;
        else {
            cnt++;
            sum+=e[i].w;
            join(u,v);
        }
        if(cnt==n-1) break;
    }
    cout<<sum;
    return 0;
}
/*
4 5 0
1 2 5
1 4 7
1 3 3
3 4 9
2 4 1

*/

