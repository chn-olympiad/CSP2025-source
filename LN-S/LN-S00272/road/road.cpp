#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
    return x*f;
}
#define PII pair<int,int>
const int N=1e4+30,inf=0x3f3f3f3f;
int n,m,k;
long long ans;
vector <pair<int,int>> G[N];
int dis[N],vis[N],tot,t[N];
int zh[N],ttot;
void work(){
    memset(dis,inf,sizeof dis);
    vis[1]=1;++tot;
    int minn=inf,mini;
    dis[1]=0;
    for(PII v:G[1]){
        dis[v.first]=v.second;
        if(dis[v.first]<minn){
            minn=dis[v.first];
            mini=v.first;
        }
    }
    while(tot<n){
        ans+=minn;
        vis[mini]=1;
        if(mini<=n) tot++;
        if(mini>n){
            zh[++ttot]=minn;
        }
        dis[mini]=0;
        memset(t,0,sizeof t);
        for(PII v:G[mini]){
            if(vis[v.first]) continue;
            if(v.second<dis[v.first]){
                dis[v.first]=v.second;
                if(mini>n) t[v.first]=1;
            }
        }

        minn=inf;
        for(int i=1;i<=n+k;i++){
            if(vis[i]) continue;
            if(dis[i]<minn){
                minn=dis[i];
                mini=i;
                if(t[i]) ttot--;
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),c=read();
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }
    for(int i=n+1;i<=n+k;i++){
        int tmp=read();
        for(int j=1;j<=n;j++){
            int c=read();
            G[i].push_back({j,c});
            G[j].push_back({i,c+tmp});
        }
    }
    work();
    for(int i=0;i<=ttot;i++){
        ans-=zh[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
