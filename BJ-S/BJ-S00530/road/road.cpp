#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10][10010],wei,ans,js[15];
struct road{
    int u,v,w;
}a[1000010];
int fa[100015];
int getfa(int x){
    if(fa[x]==x){
        return x;
    }
    else{
        fa[x]=getfa(fa[x]);
        return fa[x];
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>js[i];
        for(int j=1;j<=n;j++){
            cin>>wei;
            c[i][j]=wei;
        }
    }
    for(int i=1;i<=m;i++){
        int U=getfa(a[i].u);
        int V=getfa(a[i].v);
        if(U!=V){
            int t1=a[i].w;
            int t2=INT_MAX,tmp=0;
            for(int j=1;j<=k;j++){
                if(t2>c[i][a[i].u]+c[i][a[i].v]+js[i]){
                    t2=c[i][a[i].u]+c[i][a[i].v]+js[i];
                    tmp=j;
                }
            }
            if(t1>t2){
                ans+=t2;
                js[tmp]=0;
            }
            else{
                ans+=t1;
            }
            fa[U]=V;
        }
    }
    cout<<ans;
    return 0;
}
