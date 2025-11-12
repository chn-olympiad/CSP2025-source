#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxm = 1e6+100;
int n,m,k;
long long sum;
struct node{
    int to;
    long long w;
};
struct nod{
    int s;
    int a[maxn];
};
vector<node> g[maxm];
nod c[20];
long long d[maxn];
bool vis[maxn];
void spfa(int x){
    d[x] = 0;
    vis[x] = 1;
    queue<pair<int,int>> q;
    q.push({x,0});
    while (!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        vis[p.first] = 0;
        for (node c:g[p.first]){
            int f =  0;
            if (d[p.first]+c.w < d[c.to]){
                d[c.to] = d[p.first]+c.w;
                f = 1;
            }
            if (f == 1){
                q.push(make_pair(c.to,d[c.to]));
                vis[c.to]  =1;
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,w;
    for (int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for (int i=1;i<=k;i++){
        cin>>c[i].s;
        for (int j=1;j<=n;j++){
            cin>>c[i].a[j];
        }
    }
    for (int i=1;i<=k;i++){
        for (int j=2;j<=n;j++){
            g[m+i].push_back({j,c[i].a[j]});
            g[j].push_back({m+i,c[i].a[j]});
        }
    }
    spfa(1);
    for (int i=1;i<=n;i++){
        sum += d[i];
    }
    cout<<sum<<endl;
    return 0;
}

