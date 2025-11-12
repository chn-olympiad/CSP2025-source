#include<bits/stdc++.h>
using namespace std;
int n,m,k,jsq,ans=0x3f3f3f3f;
struct edge{
    int u,v,w;
}g[100006],tmp[100006];
bool cmp(edge x,edge y){
    return (x.w<y.w);
}
int use[15],fa[10005];
int extra[15][10005];
int extraprize[15];
int findf(int x){
    if(x==fa[x])return x;
    else return fa[x]=findf(fa[x]);
}
int f(int nx,int mx){
    int cnt=1,ans=0;
    for(int i=1;i<=mx;i++)tmp[i].u=g[i].u,tmp[i].v=g[i].v,tmp[i].w=g[i].w;
    sort(tmp+1,tmp+mx+1,cmp);
    //for(int i=1;i<=mx;i++){
    //   cout<<tmp[i].u<<' '<<tmp[i].v<<' '<<tmp[i].w<<' '<<endl;
    //}
    for(int i=1;i<=nx;i++){
        int x=findf(tmp[i].u),y=findf(tmp[i].v);
        if(x==y)continue;
        fa[x]=y;
        cnt++;
        ans+=tmp[i].w;
        if(cnt==nx)break;
    }
    //cout<<'b'<<ans<<endl;
    return ans;
}
void dfs(int x){//xdijigechengshi,yjialeduoshaobian
    jsq++;
    if(jsq>=100000)return;
    if(x>k){;
        int sum=0,jsxdh=0,nx=n,mx=m;
        for(int i=1;i<=k;i++)
            if(use[i]==1){
                sum++;
                jsxdh+=extraprize[i];
            }
        nx+=sum,mx=k*n+n;
        for(int i=1;i<=nx;i++)fa[i]=i;
        ans=min(f(nx,mx)+jsxdh,ans);
        return;
    }
    use[x]=0;
    for(int i=1;i<=n;i++){
        g[m+n*(x-1)+i].w=0x3f3f3f3f;
    }
    dfs(x+1);
    use[x]=1;
    for(int i=1;i<=n;i++){
        g[m+n*(x-1)+i].w=extra[x][i];
    }
    dfs(x+1);
    use[x]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=k*n;i++){
        g[i+m].u=n+(i/4)+1;
        if(i%4==0)g[i+m].v=n;
        else g[i+m].v=i%n;
        g[i+m].w=0x3f3f3f3f;
    }
    for(int i=1;i<=m;i++)
        cin>>g[i].u>>g[i].v>>g[i].w;
    for(int i=1;i<=k;i++){
        cin>>extraprize[i];
        for(int j=1;j<=n;j++){
            cin>>extra[i][j];
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
