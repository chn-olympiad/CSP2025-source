#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to,w;
};

edge u,v;

vector<edge> g[10007];

int a[11][10005];

int dis[10005],vis[100005],ans;
const int INF=0x3f3f3f3f;

int n,m,k;

int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;

    for(int i=1;i<=m;++i){
        cin>>u.to>>v.to>>u.w;
        v.w=u.w;
        g[u.to].push_back(v);
        g[v.to].push_back(u);
    }

    for(int i=1;i<=k;++i){
        for(int j=0;j<=n;++j){
            cin>>a[i][j];
        }
    }

    bool flag=0;
    for(int i=1;i<=k;++i){
        if(a[i][0]!=0){
            flag=1;break;
        }
    }

    if(!flag){
        for(int i=1;i<=n;++i){
            dis[i]=INF;
        }

        queue<int> q;
        q.push(1);dis[1]=0;vis[1]=1;

        for(int i=1;i<=n;++i){
            int now=q.front();
            q.pop();
            for(int j=0;j<g[q].size();++j){
                if(dis[g[q][j].to]<dis[now]+g[q][j].w){

                }
            }
        }
    }

    return 0;
}
