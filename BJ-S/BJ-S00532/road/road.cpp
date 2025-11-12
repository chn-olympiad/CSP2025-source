#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,k;
int c[maxn],a[maxn][maxn];
struct Edge {
    int u,v,w;
};
vector<Edge> to[maxn];
int fa[maxn];
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {fa[find(x)]=find(y);}
unsigned long long Kruskal(int u) {
    unsigned long long Sum=0;
    for(int i=0;i<(int)to[u].size();i++) {
        Edge tmp=to[u][i];
        int v=tmp.v,w=tmp.w;
        if(find(u)!=find(v)) {
            merge(u,v);
            fa[v]=u;
            Sum+=w;
        }
    } return Sum;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        to[u].push_back({u,v,w});
        to[v].push_back({v,u,w});
        fa[u]=v; fa[v]=u;
    }
    for(int i=1;i<=k;i++) {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
        if(c[i]==0 && a[i][1]==0) {
            cout<<0;
            return 0;
        }
        cout<<(c[i]+a[i][1]);
    }
    int anss=Kruskal(1);
    cout<<anss;
    return 0;
}
