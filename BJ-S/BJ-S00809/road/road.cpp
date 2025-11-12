#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,f[10005],ans,tot,cnt,c[15],b[12][10005],A=1,B=1,e[1005][1005],d[12],g[1005][1005],ans1=1e18,tmp;
struct node{int u,v,w;}a[1000005];
bool cmp(node p,node q){return p.w<q.w;}
int find(int x){if(f[x]==x)return x;return f[x]=find(f[x]);}
void dfs(int l){
    if(l>k){
        cnt=tot=tmp=0;
        for(int p=1;p<=k;p++)if(d[p])tmp+=c[p];
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=e[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                for(int p=1;p<=k;p++)
                    if(d[p])
                        g[i][j]=min(g[i][j],b[p][i]+b[p][j]);
                a[++tot]={i,j,g[i][j]};
            }
        sort(a+1,a+tot+1,cmp);
        for(int i=1;i<=tot;i++)
            if(find(a[i].u)!=find(a[i].v)){
                f[find(a[i].u)]=find(a[i].v);
                tmp+=a[i].w;
                if(++cnt==n-1)break;
            }
        ans1=min(ans1,tmp);
        return;
    }
    d[l]=1,dfs(l+1),d[l]=0,dfs(l+1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)e[i][j]=1e18;
    for(int i=1;i<=n;i++)f[i]=i;
    if(!k){
        for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++)
            if(find(a[i].u)!=find(a[i].v)){
                f[find(a[i].u)]=find(a[i].v);
                ans+=a[i].w;
                if(++cnt==n-1)break;
            }
        cout<<ans;
    }else{
        for(int i=1,x,y,z;i<=m;i++)cin>>x>>y>>z,e[x][y]=min(e[x][y],z);
        for(int i=1;i<=k;i++){cin>>c[i];for(int j=1;j<=n;j++){cin>>b[i][j];if(b[i][j])A=0;}if(c[i])B=0,A=0;}
        if(A)return cout<<0,0;
        if(B){
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    for(int p=1;p<=k;p++)e[i][j]=min(e[i][j],b[p][i]+b[p][j]);
                    a[++tot]={i,j,e[i][j]};
                }
            sort(a+1,a+tot+1,cmp);
            for(int i=1;i<=tot;i++)
                if(find(a[i].u)!=find(a[i].v)){
                    f[find(a[i].u)]=find(a[i].v);
                    ans+=a[i].w;
                    if(++cnt==n-1)break;
                }
            cout<<ans;
            return 0;
        }
        dfs(1);
        cout<<ans1;
    }
}