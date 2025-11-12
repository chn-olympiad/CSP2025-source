#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e4+100,K=12;
const ll inf=9e18;
int n,m,k,fa[N];
ll ans=inf,c[K],a[K][N];
bitset<K> vis;

int findRt(int u) {return fa[u]==u?u:fa[u]=findRt(fa[u]);}

void merge(int u,int v) {
    int a=findRt(u),b=findRt(v);
    if (a==b) return;
    fa[a]=b;
}

struct Edge {
    int u,v;
    ll w;
    Edge(int u_=0,int v_=0,ll w_=0): u(u_),v(v_),w(w_) {}
    bool operator<(const Edge& a) const {return w<a.w;}
};
vector<Edge> e;

struct node {
    int v;
    ll w;
    node (int v_,ll w_): v(v_),w(w_) {}
};
vector<node> vec[N];

ll kruskal() {
    for (int i=1;i<=n+k;i++) fa[i]=i;
    ll res=0;
    sort(e.begin(),e.end());
    for (auto ed:e) {
        int u=ed.u,v=ed.v,a=findRt(u),b=findRt(v);
        ll w=ed.w;
        if (a==b) continue;
        vec[u].push_back(node(v,w));
        vec[v].push_back(node(u,w));
        merge(a,b);
        res+=w;
    }
    return res;
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        int u,v; cin>>u>>v;
        ll w; cin>>w;
        e.push_back(Edge(u,v,w));
    }
    bool flag=1;
    for (int i=1;i<=k;i++) {
        cin>>c[i];
        bool check=0;
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]==0) check=1;
        }
        flag&=check;
    }
    if (flag) {
        for (int i=1;i<=k;i++) {
            for (int j=1;j<=n;j++) {
                e.push_back(Edge(i+n,j,a[i][j]));
            }
        }
        ans=kruskal();
    } else {
        for (int i=1;i<=k;i++) {
            for (int j=1;j<=n;j++) {
                e.push_back(Edge(i+n,j,a[i][j]+c[i]));
            }
        }
        ans=kruskal();
        for (int i=1;i<=k;i++) {
            if (vec[i+n].size()==1) ans-=vec[i+n][0].w;
            ans-=(vec[i+n].size()-1)*c[i];
        }
    }
    cout<<ans;
    return 0;
}
