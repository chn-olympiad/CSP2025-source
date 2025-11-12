#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    int e,w;
};
struct node{
    int n,tot2;
    ll tot;
};
const int N=1e4+40;
vector<edge> a[N];
queue<node> b;
int vis[N];
int t[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    ll ans;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=m+1;i<=m+k;i++){
        scanf("%d",&t[i]);
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            a[i].push_back({j,x});
            a[j].push_back({i,x});
        }
    }
    b.push({1,0,1});
    while(!b.empty()){
        int n0=b.front().n;
        ll tot=b.front().tot;
        int tot2=b.front().tot2;
        b.pop();
        vis[n0]=true;
        if(tot>=ans){
            continue;
        }
        if(tot2==n){
            ans=min(tot,ans);
            continue;
        }
        for(int i=0;i<a[n0].size();i++){
            int v=a[n0][i].e;
            ll w=a[n0][i].w;
            if(!vis[v]){
                if(v>m){
                    b.push({v,tot+w+t[v],tot2});
                    continue;
                }
                b.push({v,tot+w,++tot2});
            }
        }
    }
    cout<<ans;
    return 0;
}
