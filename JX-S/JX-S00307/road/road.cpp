#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int MAXM = 1e6+50;
const int MAXN = 1e4+50;
const int INF = 0x3f3f3f3f;
int dist[MAXN][MAXN];
int c[MAXN];




signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int k,m,n;
    cin>>k>>m>>n;

    memset(dist,0x3f,sizeof(dist));
    for(int i =0 ;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        dist[u][v] = min(w,dist[u][v]);
        dist[v][u] = min(w,dist[v][u]);
    }

    for(int i =0 ;i<k;i++){
        cin>>c[i];
        for(int j =0;j<n;j++){
            int x;
            cin>>x;
        }
    }

    int ans =0;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
        if(dist[i][j]!=INF){
            ans+=dist[i][j];
        }
    }
    }
    cout<<ans;

    return 0;
}
