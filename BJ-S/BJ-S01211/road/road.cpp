#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000009 * 2;
struct Edge{
    int u,v,w;
    bool operator<(Edge &other){
        return this->w<other.w;
    }
} edges[N];
int n,m,k, cnt=0;

int f[N];
int get(int x) {
    if(f[x]==x) return x;
    return f[x]=get(f[x]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ++cnt;
        cin>>edges[cnt].u>>edges[cnt].v>>edges[cnt].w;
    }
    for(int i=1;i<=k;i++){
        ++cnt;
        //0
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            ++cnt;
            cin>>edges[cnt].w;
            edges[cnt].u=j;
            edges[cnt].v=i+m;
        }
    }
    sort(edges+1,edges+cnt+1);
    for (int i=1;i<=cnt;i++){
        f[i]=i;
    }
    int ans=0;
    for (int i=1;i<=cnt;i++){
        int u=get(edges[i].u);
        int v=get(edges[i].v);
        if(u==v) continue;
        f[u]=v;
        ans+=edges[i].w;
    }
    cout<<ans;


    return 0;
}
