#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long 
const int N=1e4+10;
struct edge {int x,y,w;};
vector<edge> e,p,g;
int c[N],a[15][N],fa[N];
int GF(int o) {return (fa[o]==o)?o:fa[o]=GF(fa[o]);}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k,ret=0;cin>>n>>m>>k;
    for(int i=1,a,b,c;i<=m;i++) {
        cin>>a>>b>>c;
        e.push_back({a,b,c});
    }sort(e.begin(),e.end(),[](edge a,edge b){return a.w<b.w;});
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=k;i++) {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    for(auto ed:e) {
        if(GF(ed.x)==GF(ed.y)) continue;
        p.push_back(ed);
        fa[GF(ed.y)]=GF(ed.x);
        ret+=ed.w;
    }
    // cout<<ret<<endl;
    for(int z=0;z<(1<<k);z++) {
        g.clear();
        int cur=0;
        for(auto x:p) g.push_back(x);
        for(int i=1;i<=k;i++) {
            if(z&(1<<(i-1))) {
                cur+=c[i];
                for(int j=1;j<=n;j++) {
                    g.push_back({j,n+i,a[i][j]});
                }
            }
        }sort(g.begin(),g.end(),[](edge a,edge b){return a.w<b.w;});
        for(int i=1;i<=n+k;i++) fa[i]=i;
        for(auto ed:g) {
            if(GF(ed.x)==GF(ed.y)) continue;
            fa[GF(ed.y)]=GF(ed.x);
            cur+=ed.w;
        }ret=min(ret,cur);
        // cout<<cur<<endl;
    }cout<<ret<<endl;
    return 0;
}