#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int u,v;
    long long w;
    int need;
    bool usd;
}g[10000005];
int n,m,k;
int a[10005];
int c[10005];
int f[10005];
int top;
long long ans;
bool cmp(NODE X,NODE Y){
    if(X.usd!=Y.usd) return X.usd>Y.usd;
    return X.w<Y.w;
}
int Find(int x){
    if(f[x]==x) return x;
    f[x]=Find(f[x]);
    return f[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[++top]={u,v,w,0,0};
        g[++top]={v,u,w,0,0};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[j];
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                g[++top]={j,k,a[j]+a[k]+c[i],i,0};
                g[++top]={k,j,a[j]+a[k]+c[i],i,0};
            }
        }
    }
    sort(g+1,g+top+1,cmp);
    int used=0;
    for(int i=max(used,1);i<=top;i++){
        //cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
        //cout<<Find(g[i].u)<<" "<<Find(g[i].v)<<endl;
        if(Find(f[g[i].u])!=Find(f[g[i].v])){
            //cout<<"use:"<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
            used++;
            ans+=g[i].w;
            f[g[i].v]=Find(f[g[i].u]);
            g[i].usd=1;
            if(g[i].need!=0){
                for(int j=1;j<=top;j++){
                    if(g[j].need==g[i].need) g[j].w-=c[g[j].need],g[j].need=0;
                }
                sort(g+1,g+1+top,cmp);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
