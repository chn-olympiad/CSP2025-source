#include<bits/stdc++.h>
using namespace std;
vector<int>vc[10010];
int n,m,k,w[15][10010],c[15],mp[1010][1010];long long ans;int as[15];int fa[10010];
struct edge{int x,y,w;}ed[15001000],edd[1000010];bool flagA=true,fl[15];
bool cmp(edge x, edge y){return x.w<y.w;}
int findfa(int u){return ((fa[u]==u)?fa[u]:(fa[u]=findfa(fa[u])));}
void dfs(int now){
    long long sum=0;
    if(now==k+1){
        int mm=m;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mp[i][j]=0x3f3f3f3f;
        for(int i=1;i<=m;i++)mp[edd[i].x][edd[i].y]=mp[edd[i].y][edd[i].x]=edd[i].w,ed[i]=edd[i];
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=k;i++){
            if(fl[i]){
                sum+=c[i];
                for(int a=1;a<=n;a++){
                    for(int b=1;b<=n;b++){
                        mp[a][b]=min(mp[a][b],w[i][a]+w[i][b]);
                        mp[b][a]=min(mp[b][a],w[i][a]+w[i][b]);
                        ed[++mm]={a,b,w[i][a]+w[i][b]};
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ed[++mm]={i,j,mp[i][j]};
        sort(ed+1,ed+mm+1,cmp);
        for(int i=1;i<=mm;i++){
            if(findfa(ed[i].x)==findfa(ed[i].y))continue;
            fa[findfa(ed[i].x)]=findfa(ed[i].y);
            sum+=ed[i].w;
        }
        ans=min(ans,sum);
        return;
    }
    fl[now]=false;
    dfs(now+1);
    fl[now]=true;
    dfs(now+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>ed[i].x>>ed[i].y>>ed[i].w,edd[i]=ed[i];
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>w[i][j]; if(!w[i][j])as[i]=j;
        }
        if(!as[i])flagA=false;
    }
    if((!flagA)&&k!=0){
        ans=0x3f3f3f3f;
        dfs(1);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(as[i]==j)continue;
            ++m;ed[m]={as[i],j,w[i][j]};
        }
    }
    sort(ed+1,ed+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(findfa(ed[i].x)==findfa(ed[i].y))continue;
        fa[findfa(ed[i].x)]=findfa(ed[i].y);
        ans+=ed[i].w;
    }
    cout<<ans;
    return 0;
}
