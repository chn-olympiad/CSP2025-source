#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m,k,tot,fu,fv,x,num,fa[N],c[N],vis[N];
long long ans,tmp,res;
struct line{int u,v,w,id;}a[N],b[N];
bool cmp(line a,line b){return a.w<b.w;}
int find(int x){return fa[x]=fa[x]==x?x:find(fa[x]);}
void kruskal(){
    for(int i=1;i<=m;i++){
        fu=find(a[i].u),fv=find(a[i].v);
        if(fu==fv)continue;
        fa[fu]=fv,ans+=a[i].w,b[++tot]=a[i];
    }
}
int Sol(){
    res=0;
    for(int i=1;i<=tot;i++){
        if(vis[b[i].id]){
            fu=find(b[i].u),fv=find(b[i].v);
            if(fu==fv)continue;
            fa[fu]=fv,num--,res+=b[i].w;
            if(num==1)return res;
        }
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k,vis[0]=1;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w,a[i].id=0;
    sort(a+1,a+m+1,cmp);
    kruskal();
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>x,b[++tot]=(line){i+n,j,x,i};
    }
    sort(b+1,b+tot+1,cmp);
    for(int j=1;j<(1<<k);j++){
        tmp=0,num=n;
        for(int i=1;i<=n+k;i++)fa[i]=i,vis[i]=0;
        for(int i=1;i<=k;i++)if(j&(1<<i-1))vis[i]=1,tmp+=c[i],num++;
        Sol();
        ans=min(ans,tmp+res);
    }
    cout<<ans<<"\n";
    return 0;
}