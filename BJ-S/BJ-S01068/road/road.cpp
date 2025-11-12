#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=10010;
const int M=1200010;
struct node{
    int u,v,w;
}e[M];
int c[12];
int a[12][N];
long long ans=0;
int t=0;
int f[N];
bool cmp(node x,node y){
    return x.w<y.w;
}
int find(int x){
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        int pp=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0) pp=j;
        }
        for(int j=1;j<=n;j++){
            e[++m].u=j;
            e[m].v=pp;
            e[m].w=a[i][j];
        }
    }
    for(int i=1;i<=n;i++) f[i]=i;
    //if(k==0){
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y){
            t++;
            ans+=e[i].w;
            f[x]=y;
        }
        if(t==n-1) break;
    }
    cout<<ans<<endl;
    return 0;
    //}
    //sort(e+1,e+1+m,cmp);
}