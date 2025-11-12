#include<stdio.h>
#include<algorithm>
typedef long long ll;
constexpr int N{100000};
int a[N+5][3];
int b[N+5],c[3];
int vec[N+5];
void solve() {
    int n;
    scanf("%d",&n);
    ll ans{0};
    std::fill(c,c+3,0);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
        b[i]=std::max_element(a[i],a[i]+3)-a[i];
        ans+=a[i][b[i]];
        ++c[b[i]];
    }
    int id{int(std::max_element(c,c+3)-c)};
    if(c[id]>n>>1) {
        int tot{0};
        for(int i=1;i<=n;i++) {
            if(b[i]==id) {
                std::sort(a[i],a[i]+3);
                vec[++tot]=a[i][1]-a[i][2];
            }
        }
        std::sort(vec+1,vec+tot+1);
        while(tot>n>>1) {
            ans+=vec[tot--];
        }
    }
    printf("%lld\n",ans);
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--) {
        solve();
    }
    return 0;
}
/*
const mod=998244353,mul=31,add=17;
var seed;
function set_seed(s) {
    seed=s;
    console.log("Seed reset to "+s+".");
}
function next_number() {
    return seed=(seed*mul+add)%mod;
}
function rand_in_range(l,r) {
    return next_number()%(r-l+1)+l;
}
const n=10;
var vis,edges,adj,dis;
function initialize() {
    console.log("Initializing.");
    vis=[];
    for(var i=0;i!=n;i++) {
        vis.push(0);
    }
    edges=[];
    function add_edge(a,b) {
        edges.push([a,b,rand_in_range(1,100)]);
    }
    function generate_a_tree() {
        var prufer=[];
        for(var i=0;i!=n-2;i++) {
            prufer.push(rand_in_range(0,n-1));
        }
        prufer.push(n-1);
        // console.log("prufer =",prufer);
        var degree=[];
        for(var i=0;i!=n;i++) {
            degree.push(1);
        }
        for(var i=0;i!=n-2;i++) {
            ++degree[prufer[i]];
        }
        // console.log("degree =",degree);
        var cur=0,lst=-1;
        for(var i=0;i!=n-1;i++) {
            while(degree[cur]!=1) {
                ++cur;
            }
            var res=-1;
            if(lst!=-1&&lst<cur&&degree[lst]==1) {
                res=lst;
            }
            else if(cur!=n) {
                res=cur;
            }
            else {
                console.assert();
            }
            add_edge(res,prufer[i]);
            --degree[res],--degree[prufer[i]];
            lst=prufer[i];
        }
    }
    generate_a_tree();
    function generate_extra_edges() {
        var m=rand_in_range(0,n*2);
        for(var i=0;i!=m;i++) {
            var u,v;
            do {
                u=rand_in_range(0,n-1);
                v=rand_in_range(0,n-1);
            } while (u==v);
            add_edge(u,v);
        }
    }
    generate_extra_edges();
    console.log("edges =",edges);
    adj=[];
    for(var i=0;i!=n;i++) {
        adj.push([]);
    }
    for(var i=0;i!=edges.length;i++) {
        console.log(i,edges[i]);
        adj[edges[i][0]].push([edges[i][1],edges[i][2]]);
        adj[edges[i][1]].push([edges[i][0],edges[i][2]]);
    }
    console.log("adj =",adj);
    dis=[];
    for(var i=0;i!=n;i++) {
        dis.push(n*100);
    }
    dis[n-1]=0;
    var que=[n-1];
    for(var i=0;i!=que.length;i++) {
        var u=que[i];
        // console.log("visit",u);
        for(var j=0;j!=adj[u].length;j++) {
            var v=adj[u][j][0],w=adj[u][j][1];
            // console.log(u,v,w,dis[u],dis[v]);
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                que.push(v);
            }
        }
    }
    console.log("dis =",dis);
    console.log("Initialization finished.");
}
*/