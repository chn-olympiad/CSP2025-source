#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int to,next,w;
    bool is_using;
} edge[2050005];
int head[10015],cnt=0;

int n,m,k;
int c[15];

void add(int u,int v,int w,int type){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    edge[cnt].is_using = type;

    head[u] = cnt;
    cnt ++;
}

void dij(int sp){
    vector<int> dist(n+k,0x3f3f3f3f);
    vector<bool> flag(n+k);
    vector<int> pre(n+k,-1);

    for(int i=head[sp];i!=-1;i=edge[i].next){
        dist[edge[i].to] = edge[i].w;
    }
    dist[sp] = 0,flag[sp] = true;

    for(int i=0;i<n+k-1;i++){
        int min_d=0x3f3f3f3f,p;
        for(int j=1;j<=n+k;j++){
            if(dist[j] < min_d && !flag[j]){
                min_d = dist[j];
                p = j;
            }
        }

        for(int j=head[p];j!=-1;j=edge[j].next){
            if(dist[edge[j].to] > dist[p] + edge[j].w + (p>n?c[p-n]:0)){
                dist[edge[j].to] = dist[p] + edge[j].w + (p>n?c[p-n]:0);
                pre[edge[j].to] = j;
            }
        }

        flag[p] = true;
    }

    for(int i=1;i<=n+k;i++){
        if(pre[i] == -1) continue;
        edge[pre[i]].is_using = true;
    }

    return;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;

    for(int i=1;i<=n+k;i++){
        head[i] = -1;
    }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        add(u,v,w,false);
        add(v,u,w,false);
    }

    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            add(n+i,j,w,false);
            add(j,n+i,w,false);
        }
    }

    for(int i=1;i<=n;i++){
        dij(i);
        // cout<<i<<"finish"<<endl;
    }

    // cout<<"finish"<<endl;

    int ans = 0;
    for(int i=0;i<cnt;i++){
        if(edge[i].is_using){
            ans += edge[i].w;
        }
    }
    
    cout<<ans;

    return 0;
}