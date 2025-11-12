#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+100, M = 1e6+10;
int n,m,k,fa[N],ans,cnt,a[N];
struct edge { int u,v,w; } e[M];
bool cmp(edge a,edge b) { return a.w<b.w; }
void init() { for(int i=1;i<=n+10;i++) fa[i]=i; }
int find(int x) { return fa[x]==x ? x : (fa[x]=find(fa[x])); }
void merge(int x,int y) { fa[x]=y; }
signed main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    for(int j=1;j<=k;j++)
        for(int i=1,t;i<=n;i++)
            cin>>t;
    init();
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++) {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)==find(v)) continue;
        merge(u,v); ans+=w,cnt++;
        if(cnt==n-1) break;
    }
    cout<<ans;
    return 0;
}