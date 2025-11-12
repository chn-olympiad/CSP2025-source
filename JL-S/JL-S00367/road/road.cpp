#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e4+10;
const int M = 1e6+10;
struct node {
    int be,to,w;
}adj[M];
int fa[N],n,m,k,c[N];

int find(int x) {
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void merge(int x,int y) {
    x=find(x);
    y=find(y);
    if(y>x) swap(x,y);
    fa[x]=y;
}

void init(int n) {
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

bool cmp(node x,node y) {
    return x.w<y.w;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m>>k;
    init(n);
    int ans =0;
    for (int i=1;i<=m;i++) {
        cin>>adj[i].be>>adj[i].to>>adj[i].w;
    }
    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }
    sort(adj+1,adj+m+1,cmp);
    for (int i=1;i<=m;i++) {
        if(find(adj[i].be)!=find(adj[i].to)){
            merge(adj[i].be,adj[i].to);
            ans+=adj[i].w;
        }
    }
    cout << ans;
    return 0;
}