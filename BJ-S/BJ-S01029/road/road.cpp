#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
}e[1000010];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int cnt,sum=0;
int f[1000100];
int find(int x){
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[++cnt].u=u,e[cnt].v=v,e[cnt].w=w;
    }
    for(int i=1;i<=n;i++)
        f[i]=i;
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=n;i++){
        int u=e[i].u,v=e[i].v;
        int fu=find(u);
        int fv=find(v);
        if(fu!=fv){
            f[fu]=fv;
            sum++;
            ans+=e[i].w;
            if(sum==n-1){
                cout<<ans;
                return 0;
            }
        }
    }
    return 0;
}
