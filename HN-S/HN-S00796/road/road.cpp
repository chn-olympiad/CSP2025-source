#include<bits/stdc++.h>
const int N=2e6+5,INF=1e9;
using namespace std;
int n,m,k,f[N],s;
struct nd{
    int u,v,w;
}e[N];
int gf(int x){
    if(f[x]==x)return x;
    return f[x]=f[f[x]];
}
void mg(int x,int y){
    f[gf(x)]=gf(y);
}
bool cmp(nd x,nd y){return x.w<y.w;}
signed main(){
    ios::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1,c;i<=k;i++){
        cin>>c;
        for(int j=1,x;j<=n;j++){
            cin>>x;
            e[++m]=(nd){n+i,j,x};
        }
    }
    for(int i=1;i<=n+k;i++)f[i]=i;
    sort(e+1,e+1+m,cmp);
    for(int i=1,u,v,w;i<=m;i++){
        u=e[i].u,v=e[i].v,w=e[i].w;
        if(gf(u)==gf(v))continue;
        mg(u,v),s+=w;
    }
    cout<<s<<endl;
    return 0;
}