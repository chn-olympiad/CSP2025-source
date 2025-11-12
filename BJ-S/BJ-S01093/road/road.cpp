#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
};
int n,m,k;
int f[10005];
node adj[1000005];
int xb=0;
long long ans=0;
int c;
int a[10005];
int findr(int x){
    if(f[x]==x) return x;
    return f[x]=findr(f[x]);
}
void un(int x,int y){
    f[findr(x)]=findr(y);
}
bool cmp(node x,node y){
    return x.w>y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        adj[++xb]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            for(int l=1;l<j;l++){
                adj[++xb]={j,l,a[j]+a[l]+c};
            }
        }
    }
    sort(adj+1,adj+xb+1,cmp);
    int sum=n-1;
    while(sum){
        u=adj[xb].u,v=adj[xb].v,w=adj[xb].w;
        if(findr(u)!=findr(v)){
            ans+=w;
            un(u,v);
            sum--;
            //cout<<u<<' '<<v<<' '<<w<<endl;
        }
        xb--;
    }
    cout<<ans;
}
