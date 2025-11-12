#include<bits/stdc++.h>
using namespace std;
const int N=10010,inf=0x3f3f3f3f;

inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

struct zyx{
    int to,w;
};
vector<zyx> e[N];
int n,m,k,cost[20][N],dis[N],vis[N],c[N],flag[N];

long long check(){
    long long res=0;
    int cnt=n; 
    for(int i=1;i<=k;i++)e[i+n].clear();
    // cout<<"check一次\n";
    for(int i=1;i<=k;i++){
        if(flag[i]){
            cnt++;
            res+=c[i];
            // cout<<"新加入一个"<<i<<'\n';
            for(int j=1;j<=n;j++){
                e[cnt].push_back((zyx){j,cost[i][j]});
                e[j].push_back((zyx){cnt,cost[i][j]});
            }
        }
    }
    for(int i=1;i<=cnt;i++)dis[i]=inf;
    for(int i=1;i<=cnt;i++)vis[i]=0;
    dis[1]=0;
    for(int i=1;i<=cnt;i++){
        int minn=0;
        dis[0]=inf;
        for(int j=1;j<=cnt;j++){
            if(vis[j])continue;
            if(dis[j]<dis[minn])minn=j;
        }
        // cout<<"dis最小的点是"<<minn<<'\n';
        res+=dis[minn];
        vis[minn]=1;
        for(int j=0;j<(int)e[minn].size();j++){
            int to=e[minn][j].to;
            if(vis[to])continue;
            if(dis[to]>e[minn][j].w)dis[to]=e[minn][j].w;
        }
    }
    for(int i=1;i<=k;i++){
        if(flag[i]){
            for(int j=1;j<=n;j++){
                e[j].pop_back();
            }
        }
    }
    return res;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        e[u].push_back((zyx){v,w});
        e[v].push_back((zyx){u,w});
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++)cost[i][j]=read();
    }
    if(k>5||n>1000){
        for(int i=1;i<=k;i++)flag[i]=1;
        cout<<check()<<'\n';
        return 0;
    }
    long long ans=1e18;
    for(int i=0;i<(1<<k);i++){
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1))){
                flag[j]=1;
            }
            else flag[j]=0;
        }
        ans=min(ans,check());
    }
    cout<<ans;
    return 0;
}