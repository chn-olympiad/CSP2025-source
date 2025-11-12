#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,ans,g[10025][10025],dis[10025];
bool b[10025];
int prim(int x){
    memset(dis,0x3f,sizeof(dis));
    dis[x]=0;
    b[x]=1;
    while(1){
        int u=-1,minn=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            if(minn>dis[i]&&!b[i]){
                u=i;
                minn=dis[i];
            }
        }
        if(u==-1)break;
        b[u]=1;
        for(int i=1;i<=n;i++){
            dis[i]=min(dis[i],g[u][i]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dis[i];
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(g,0x3f,sizeof(g));
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
    }
    cout<<prim(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
