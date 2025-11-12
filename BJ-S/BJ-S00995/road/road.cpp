#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e3+5;
struct deg{
    long long u,v,w;
}c[M*M];
long long a[M][M];
long long b[N],f[M*M];
long long ans;
bool cmp(deg A,deg B){
    return A.w < B.w;
}
int find(int x){
    if (x==f[x]) return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if (x!=y) f[x]=y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(a,0x3f3f,sizeof a);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=min(a[u][v],w);
    }
    for (int i=1;i<=k;i++){
        int x;
        cin>>x;
        for (int i=1;i<=n;i++) cin>>b[i];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j) continue;
                a[i][j]=a[j][i]=min(a[i][j],x+b[i]+b[j]);
            }
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            c[++cnt].u=i;
            c[cnt].v=j;
            c[cnt].w=a[i][j];
        }
    }
    sort(c+1,c+cnt+1,cmp);
    for (int i=1;i<=cnt;i++) f[i]=i;
    for (int i=1;i<=cnt;i++){
        if (find(c[i].u)!=find(c[i].v)){
            merge(c[i].u,c[i].v);
            ans+=c[i].w;
        }
    }
    cout<<ans<<endl;
    return 0;
}
