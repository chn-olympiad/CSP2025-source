#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],ans,k,x,g[10010];
struct node{
    int u;
    int v;
    int w;
}nd[1000010];
bool cmp(node a,node b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=m;i++){
            cin>>nd[i].u>>nd[i].v>>nd[i].w;
        }
        sort(nd+1,nd+1+m,cmp);
        for(int i=1;i<=m;i++){
            if(a[nd[i].u]==1&&a[nd[i].v]==1) continue;
            a[nd[i].u]=1,a[nd[i].v]=1,ans+=nd[i].w;
        }
    }
    else{
        for(int i=1;i<=m;i++){
            cin>>nd[i].u>>nd[i].v>>nd[i].w;
        }
        for(int i=1;i<=k;i++){
            cin>>x;
            for(int j=1;j<=n;j++){
                cin>>g[j];
                for(int k=j-1;k>=1;k--){
                    nd[++m].u=j;
                    nd[m].v=k;
                    nd[m].w=g[k]+g[j]+x;
                }
            }
        }
        sort(nd+1,nd+1+m,cmp);
        for(int i=1;i<=m;i++){
            if(a[nd[i].u]==1&&a[nd[i].v]==1) continue;
            a[nd[i].u]=1,a[nd[i].v]=1,ans+=nd[i].w;
        }
    }
    cout<<ans;
    return 0;
}
