#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
struct edge{
    int u,v;
    long long w;
}e[20001000];
int cnt=0;
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int fa[10100];
int fin(int x){
    if(fa[x]==x){
        return x;
    }
    else{
        return fa[x]=fin(fa[x]);
    }
}
void K(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(e+1,e+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        int u=fin(e[i].u);
        int v=fin(e[i].v);
        if(u==v){
            continue;
        }
        ans+=e[i].w;
        fa[u]=v;
    }
}
int a[10010]={},f=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[++cnt].u>>e[cnt].v>>e[cnt].w;
    }
    for(int i=1;i<=k;i++){
        long long add=0;
        cin>>add;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            if(a[j]==0){
                f=j;
            }
        }
        for(int j=1;j<=n;j++){
            e[++cnt].u=f;
            e[cnt].v=j;
            e[cnt].w=a[j];
        }
    }
    K();
    cout<<ans<<endl;
    return 0;
}
