#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k,cnt,ans,num;
struct road{
    int u,v,w;
}r[N];
int c[N];
int fa[N];
int a[15][N];

bool cmp(road x,road y){
    return x.w<y.w;
}

int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>r[i].u>>r[i].v>>r[i].w;
    }
    num=m;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        for(int x=1;x<n;x++){
            for(int y=x+1;y<=n;y++){
                r[++num]={x,y,a[i][x]+a[i][y]+c[i]};
            }
        }
    }
    sort(r+1,r+1+num,cmp);
    for(int i=1;i<=num;i++){
        if(find(r[i].u)!=find(r[i].v)){
            cnt++;
            fa[find(r[i].u)]=find(r[i].v);
            ans+=r[i].w;
        }
        if(cnt==n-1) break;
    }
    cout<<ans;
    return 0;
}
