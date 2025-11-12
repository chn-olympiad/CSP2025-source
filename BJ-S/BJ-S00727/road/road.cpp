#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+5;

struct node {
    ll to,cost;
};

ll n,m,k;
vector<node> g[N];
bool vis[N];

bool cmp(node x,node y) {
    return x.cost<y.cost;
}

int ans=0;

void Prim(int s) {
    vector<int> a;
    a.push_back(s);
    vis[s]=true;
    while(a.size()<n) {
        for(auto i:a) {
            sort(g[i].begin(),g[i].end(),cmp);
            for(auto j:g[i]) {
                if(!vis[j.to]) {
                    a.push_back(j.to);
                    vis[j.to]=true;
                    ans+=j.cost;
                }
            }
        }
    }
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    Prim(1);

    cout<<ans;

    return 0;
}