#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
#define int long long
int n,m,k;
struct node{
    int u,v,w;
}e[M<<1];
int f[N+K];
bool cmp(node a,node b){
    return a.w<b.w;
}
void init(){
    for(int i=1;i<=n+k;i++)f[i]=i;
}
int findd(int x){
    if(f[x]==x)return x;
    else return f[x]=findd(f[x]);
}
void unionn(int x,int y){
    x=findd(x),y=findd(y);
    if(x!=y)f[x]=y;
}
int c[N],a[N][N];
int idx=0;
int Kruskal(){
    init();
    sort(e+1,e+idx+1,cmp);
    int ans=0,cnt=0;
    for(int i=1;i<=idx;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=findd(u),fv=findd(v);
        if(fu==fv)continue;
        unionn(u,v);
        ans+=w,cnt++;
        if(cnt>=n+k-1)return ans;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[++idx]={u,v,w};
    }
    if(k==0){
        sort(e+1,e+1+m,cmp);
        cout<<Kruskal();
        return 0;
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
            e[++idx]={n+j,i,a[j][i]};
        }
    }
    cout<<Kruskal()<<'\n';
    /*for(int i=1;i<=idx;i++){
        printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
    }*/
    return 0;
}
