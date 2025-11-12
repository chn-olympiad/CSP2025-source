#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[10001];
struct path{
    int u,v,w;
}a[1000001];
int findfa(int x){
    if(fa[x]==x)return x;
    return fa[x]=findfa(fa[x]);
}
int sum[100001];
bool cmp(path x,path y){
    return x.w<y.w;
}
long long ans;
int c[13][10001];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
            if(j!=0)a[++m].u=i,a[m].v=j,a[m].w=c[i][j];
        }
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=n;i++)sum[i]=1ll;
    for(int i=1;i<=m;i++){
        int anx=findfa(a[i].u),any=findfa(a[i].v);
        if(anx==any)continue;
        ans+=a[i].w;
        sum[fa[any]]=sum[fa[anx]]+sum[fa[any]];
        sum[fa[anx]]=sum[fa[anx]]+sum[fa[any]];
        fa[anx]=fa[any];
        if(sum[fa[anx]]==n||sum[fa[any]]==n){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
