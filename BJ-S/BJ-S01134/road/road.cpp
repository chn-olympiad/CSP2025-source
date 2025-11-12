#include <bits/stdc++.h>
using namespace std;

const int N=10010,M=1e6+10;
struct node{
    int u,v,w;
}a[M];//存储边
int n,m,k,fa[N],c[15][N],ans;//fa数组为并查集数组

bool cmp(node x,node y){
    return x.w<y.w;
}
int fd(int x){
    if(fa[x]==x)return x;
    else {
        fa[x]=fd(fa[x]);
        return fa[x];
    }
}
void connect(int x,int y){
    int nx=fd(x),ny=fd(y);
    fa[nx]=ny;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=k;i++){
        cin>>c[i][0];
        for(int j=1;j<=n;j++)cin>>c[i][j];
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(fd(a[i].u)==fd(a[i].v))continue;
        connect(a[i].u,a[i].v);
        ans+=a[i].w;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}