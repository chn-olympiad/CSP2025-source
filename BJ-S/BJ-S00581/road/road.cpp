#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
    int u,v,w;
}ed[2000100];
int p,a[1001000]={},fa[20010]={};
bool cmp(node x,node y){
    return x.w<y.w;
}
int fi(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=fi(fa[x]);
    }
}
void mer(int x,int y){
    if(fa[x]!=fa[y]){
        fa[x]=y;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>p;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            ed[m+j].u=n+i;
            ed[m+j].v=j;
            ed[m+j].w=a[j];
        }
    }
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    int sum=0,ans=0;
    sort(ed+1,ed+m+n*k+1,cmp);
    for(int i=1;i<=m+n*k;i++){
        int u=ed[i].u;
        int v=ed[i].v;
        int w=ed[i].w;
        if(fi(u)!=fi(v)){
            ans++;
            mer(u,v);
            sum+=w;
            if(ans==n+k-1){
                break;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
