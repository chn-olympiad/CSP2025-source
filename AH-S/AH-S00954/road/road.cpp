#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=10050,MAXM=1000050;
struct edge{
    int u,v,w;
}E[MAXM],e[11][MAXN];
bool operator<(edge a,edge b){
    return a.w<b.w;
}
int vis[MAXM],w[22],ch[22],n,m,k;
int fa[MAXN];
long long ans;
int root(int x){
    return (fa[x]==x)?x:(fa[x]=root(fa[x]));
}
void solve(){
    int cnt=0;
    long long sum=0;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        if(cnt==n-1)break;
        int u=root(E[i].u),v=root(E[i].v);
        if(u==v)continue;
        cnt++;
        sum+=E[i].w;
        fa[u]=v;
        vis[i]=1;
    }
    ans=sum;
}
edge G[1050][MAXN];
void dfs(int x,int stt,long long pre){
    if(x>k)return;
    dfs(x+1,stt,pre);
    pre+=w[x];
    int STT=stt|(1<<(x-1));
    int goal=__builtin_popcount(stt)+n;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    int szi=goal-1,szj=n,cnt=0;
    long long sum=0;
    for(int i=1,j=1;i<=szi||j<=szj;){
        if(cnt==goal)break;
        edge&I=G[stt][i],&J=e[x][j],now;
        if(i>szi||I.w>J.w&&j<=szj)now=J,j++;
        else now=I,i++;
        int u=root(now.u),v=root(now.v);
        if(u==v)continue;
        cnt++,sum+=now.w,fa[u]=v;
        G[STT][cnt]=now;
    }
   // cout<<STT<<" "<<sum<<" "<<pre<<" "<<cnt<<endl;
    //for(int i=1;i<=cnt;i++){
     //   cout<<G[STT][i].u<<" "<<G[STT][i].v<<" "<<G[STT][i].w<<endl;
    //}
    ans=min(ans,sum+pre);
    dfs(x+1,STT,pre);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

        scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
    }
    sort(E+1,E+1+m);
    for(int i=1;i<=k;i++){
        scanf("%d",&w[i]);
        for(int j=1;j<=n;j++){
        scanf("%d",&e[i][j].w);
            e[i][j].v=j;
            e[i][j].u=i+n;
        }
        sort(e[i]+1,e[i]+1+n);
    }
    solve();
    //cout<<ans<<endl;
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(vis[i]==1)G[0][++cnt]=E[i];
        //,cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<endl;
    }
    dfs(1,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
